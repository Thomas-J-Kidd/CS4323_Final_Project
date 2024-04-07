/*
Author: Thomas Kidd
Name: Proccess Manager
Date written: 04/07/2024
Updated:
    - By: Thomas Kidd on 04/07/2023
*/
#include "ProcessManager.h"
#include <iostream>
#include <sys/wait.h>
#include <unistd.h>

ProcessManager::ProcessManager() {
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
    commandProcessors["CREATE_ACCOUNT"] = [this](const Command& cmd) -> bool { return processCreateAccount(cmd); };
    // Add other command processors similarly
}

bool ProcessManager::processCreateAccount(const Command& cmd) {
    // Forking logic as previously discussed
    pid_t pid = fork();

    if (pid == -1) {
        // Fork failed
        std::cerr << "Failed to fork for CREATE_ACCOUNT" << std::endl;
        return false;
    } else if (pid == 0) {
        // Child process
        std::cout << "Creating account: \n\tusername: " << cmd.parameters.at("username") << "\n\tpassword: " << cmd.parameters.at("password")<<std::endl;
        exit(0); // Exit child process
    } else {
        // Parent process waits for child to complete
        int status;
        waitpid(pid, &status, 0);
        return WIFEXITED(status) && WEXITSTATUS(status) == 0;
    }
}

// Implement other command processing functions similarly...
