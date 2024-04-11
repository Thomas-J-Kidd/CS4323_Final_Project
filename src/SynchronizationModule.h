#ifndef SYNCHRONIZATIONMODULE_H
#define SYNCHRONIZATIONMODULE_H

#include <mutex>
#include <condition_variable>
#include <map>
#include <queue>
#include <string>

class SynchronizationModule {
public:
    void lockResource(const std::string& resourceId, const std::string& processId);
    void unlockResource(const std::string& resourceId, const std::string& processId);
    void waitForCondition(const std::string& resourceId);
    void notify(const std::string& resourceId);
    void notifyAll(const std::string& resourceId);
private:
    struct Monitor {
        std::mutex mutex;
        std::condition_variable conditionVariable;
        std::queue<std::string> waitQueue;
    };
    std::map<std::string, Monitor> monitors;
};

#endif // SYNCHRONIZATIONMODULE_H
