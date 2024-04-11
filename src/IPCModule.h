#ifndef IPCMODULE_H
#define IPCMODULE_H

#include <string>
#include "SynchronizationModule.h" // Update this include path if necessary

struct Transaction {
    std::string type;
    std::string account_number;
    double amount;
    std::string status;
    std::string timestamp;

    std::string serialize() const;
};

class SharedMemorySegment {
public:
    void createSegment(const std::string& segmentId);
    void updateSegment(const std::string& segmentId, const Transaction& transaction);
    std::string readSegment(const std::string& segmentId);
private:
    std::map<std::string, std::string> data;
    std::mutex mutex;
};

class IPCModule {
public:
    IPCModule();
    void recordTransaction(const std::string& processId, const std::string& segmentId, 
                           const std::string& transactionType, const std::string& accountNumber, 
                           double amount, const std::string& status);
    std::string readTransaction(const std::string& processId, const std::string& segmentId);
private:
    SharedMemorySegment sharedMemory;
    SynchronizationModule syncModule;
};

#endif // IPCMODULE_H
