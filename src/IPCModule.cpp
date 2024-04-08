#include <iostream>
#include <map>
#include <string>
#include <mutex>
#include <chrono>
#include <sstream>
#include "SynchronizationModule.cpp"  // Make sure to include the correct header file.

struct Transaction {
    std::string type;
    std::string account_number;
    double amount;
    std::string status;
    std::string timestamp;

    std::string serialize() const {
        std::stringstream ss;
        ss << type << " " << account_number << " " << amount << " " << status << " " << timestamp;
        return ss.str();
    }
};

class SharedMemorySegment {
private:
    std::map<std::string, std::string> data;
    std::mutex mutex;

public:
    void createSegment(const std::string& segmentId) {
        std::lock_guard<std::mutex> lock(mutex);
        data[segmentId] = "";
    }

    void updateSegment(const std::string& segmentId, const Transaction& transaction) {
        std::lock_guard<std::mutex> lock(mutex);
        data[segmentId] = transaction.serialize();
    }

    std::string readSegment(const std::string& segmentId) {
        std::lock_guard<std::mutex> lock(mutex);
        auto it = data.find(segmentId);
        if (it != data.end()) {
            return it->second;
        }
        return "";
    }
};

class IPCModule {
private:
    SharedMemorySegment sharedMemory;
    SynchronizationModule syncModule;

public:
    IPCModule() {}

    void recordTransaction(const std::string& processId, const std::string& segmentId, 
                           const std::string& transactionType, const std::string& accountNumber, 
                           double amount, const std::string& status) {
        auto now = std::chrono::system_clock::now();
        auto time_now = std::chrono::system_clock::to_time_t(now);
        std::string timestamp = std::ctime(&time_now);

        if (!timestamp.empty() && timestamp.back() == '\n') {
            timestamp.pop_back();
        }

        syncModule.lockResource(segmentId, processId);
        
        Transaction transaction{transactionType, accountNumber, amount, status, timestamp};
        sharedMemory.updateSegment(segmentId, transaction);
        
        syncModule.unlockResource(segmentId, processId);
    }

    std::string readTransaction(const std::string& processId, const std::string& segmentId) {
        syncModule.lockResource(segmentId, processId);
        std::string result = sharedMemory.readSegment(segmentId);
        syncModule.unlockResource(segmentId, processId);
        return result;
    }
};
