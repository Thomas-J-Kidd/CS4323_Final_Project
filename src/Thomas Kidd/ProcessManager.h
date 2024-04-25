/*
Author: Thomas Kidd
Name: Proccess Manager
Date written: 04/07/2024
Updated:
    - By: Thomas Kidd on 04/07/2023
*/
#ifndef PROCESSMANAGER_H
#define PROCESSMANAGER_H

#include "InputParser.h"
#include "IPCModule.h"  // Include IPCModule header
#include "SynchronizationModule.h"  // Include SynchronizationModule header
#include <memory>
#include <functional>
#include <map>

class ProcessManager {
public:
    ProcessManager();
    void initialize(); // Simplified for this example

    // Process commands from an InputParser instance
    void processCommands(InputParser& parser);

private:
    // Example placeholder for module interaction
    std::shared_ptr<IPCModule> ipcModule;
    std::shared_ptr<SynchronizationModule> syncModule;

    std::map<std::string, std::function<bool(const Command&)>> commandProcessors;

    // Command processing functions
    bool processCreateAccount(const Command& cmd);
    bool processCloseAccount(const Command& cmd);
    bool processDeposit(const Command& cmd);
    bool processTransfer(const Command& cmd);
    bool processWithdraw(const Command& cmd);
    bool processInquiry(const Command& cmd);

    // Helper function to set up command processors
    void setupCommandProcessors();
};

#endif // PROCESSMANAGER_H
