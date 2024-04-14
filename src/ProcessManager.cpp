/*
Author: Thomas Kidd
Name: Proccess Manager
Date written: 04/07/2024
Updated:
    - By: Thomas Kidd on 04/07/2023
*/
#include "ProcessManager.h"
#include "IPCModule.h"
#include "SynchronizationModule.h"
#include "Account.h"
#include <iostream>
#include <sys/wait.h>
#include <unistd.h>

ProcessManager::ProcessManager() : ipcModule(std::make_shared<IPCModule>()), 
                                   syncModule(std::make_shared<SynchronizationModule>()) {
    setupCommandProcessors();
}


void ProcessManager::initialize() {
    // Initialization logic for IPC and Synchronization, if any
}

void ProcessManager::processCommands(InputParser& parser) {
    Command cmd;
    while (parser.getNextCommand(cmd)) {
        auto it = commandProcessors.find(cmd.type);
        if (it != commandProcessors.end()) {
            bool success = it->second(cmd);
            if (!success) {
                std::cerr << "Command processing failed for: " << cmd.type << std::endl;
            }
        } else {
            std::cerr << "Unknown command: " << cmd.type << std::endl;
        }
    }
}

void ProcessManager::setupCommandProcessors() {
    
    commandProcessors["Create"] = [this](const Command& cmd) -> bool { return processCreateAccount(cmd); };
    // commandProcessors["Close"] = [this](const Command& cmd) -> bool { return processCloseAccount(cmd); };
    // commandProcessors["Deposit"] = [this](const Command& cmd) -> bool { return processDeposit(cmd); };
    // commandProcessors["Withdraw"] = [this](const Command& cmd) -> bool { return processWithdraw(cmd); };
    // commandProcessors["Transfer"] = [this](const Command& cmd) -> bool { return processTransfer(cmd); };
    // commandProcessors["Inquiry"] = [this](const Command& cmd) -> bool { return processInquiry(cmd); };

    // Add mappings for other commands as necessary
}

bool ProcessManager::processCreateAccount(const Command& cmd) {
    pid_t pid = fork();
    if (pid == -1) {
        std::cerr << "Failed to fork for Create Account" << std::endl;
        return false;
    } else if (pid == 0) {
        if (exists(cmd.userId)) {
            std::cerr << "Account already exists for User ID: " << cmd.userId << std::endl;
            exit(1);
        }
        Account newAccount(cmd.userId);
        newAccount.deposit(cmd.parameters.begin()->second);
        // Child process logic for creating an account
        std::cout << "Creating account for User ID: " << cmd.userId << std::endl;
        // Insert logic to create an account in the banking system here
        

        exit(0);
    } else {
        // Parent process waits for the child to complete
        int status;
        waitpid(pid, &status, 0);
        return WIFEXITED(status) && WEXITSTATUS(status) == 0;
    }
}

// Implement other command processing functions similarly...
