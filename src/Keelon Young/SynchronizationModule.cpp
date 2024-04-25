/*
Author: Keelon Viney-Young
Name: Synchronization Module
Date written: 04/07/2024
Updated:
    - By: Keelon V. Young on 04/07/2023
*/

#include <mutex>
#include <condition_variable>
#include <map>
#include <queue>
#include <iostream>

using ResourceId = std::string;

class SynchronizationModule {
private:
    struct Monitor {
        std::mutex mutex;
        std::condition_variable conditionVariable;
        std::queue<std::string> waitQueue;  // Queue to track waiting processes (process identifiers can be added)
    };

    std::map<ResourceId, Monitor> monitors;

public:
    void lockResource(const ResourceId& resourceId, const std::string& processId) {
        auto& monitor = monitors[resourceId];
        std::unique_lock<std::mutex> lock(monitor.mutex);
        monitor.waitQueue.push(processId);
        // Only wait if this process is not at the front of the queue
        monitor.conditionVariable.wait(lock, [&monitor, &processId] { return monitor.waitQueue.front() == processId; });
        // Once the process is at the front of the queue and notified, it can proceed and should be removed from the queue
        monitor.waitQueue.pop();
    }

    void unlockResource(const ResourceId& resourceId, const std::string& processId) {
        auto& monitor = monitors[resourceId];
        std::lock_guard<std::mutex> lock(monitor.mutex);
        // Notify the next waiting process, if any
        if (!monitor.waitQueue.empty()) {
            monitor.conditionVariable.notify_one();
        }
        std::cout << "Process " << processId << " released resource " << resourceId << std::endl;
    }

    // These methods can be used for more fine-grained control over condition variables
    void waitForCondition(const ResourceId& resourceId) {
        auto& monitor = monitors[resourceId];
        std::unique_lock<std::mutex> lock(monitor.mutex);
        monitor.conditionVariable.wait(lock);
    }

    void notify(const ResourceId& resourceId) {
        auto& monitor = monitors[resourceId];
        std::lock_guard<std::mutex> lock(monitor.mutex);
        monitor.conditionVariable.notify_one();
    }

    void notifyAll(const ResourceId& resourceId) {
        auto& monitor = monitors[resourceId];
        std::lock_guard<std::mutex> lock(monitor.mutex);
        monitor.conditionVariable.notify_all();
    }
};
