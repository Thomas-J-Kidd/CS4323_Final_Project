#include "InputParser.h"
#include <fstream>
#include <sstream>
#include <iostream>

// Load and parse the file at the given filePath
bool InputParser::loadAndParse(const std::string& filePath) {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filePath << std::endl;
        return false;
    }

    std::string line;
    while (std::getline(file, line)) {
        Command cmd = parseLine(line);
        if (!cmd.type.empty()) {
            commandQueue.push(cmd);
        } else {
            std::cerr << "Warning: Skipping invalid or incomplete command line." << std::endl;
        }
    }

    file.close();
    return true;
}

// Retrieve the next command from the queue
bool InputParser::getNextCommand(Command& command) {
    if (commandQueue.empty()) {
        return false;
    }

    command = commandQueue.front();
    commandQueue.pop();
    return true;
}

// Utility function to parse a single line into a Command struct
Command InputParser::parseLine(const std::string& line) {
    std::istringstream stream(line);
    Command cmd;

    // First, extract the user ID
    std::getline(stream, cmd.userId, ' ');

    // Next, extract the command type
    std::getline(stream, cmd.type, ' ');

    // The rest of the line consists of optional parameters, handled similarly to your original approach
    std::string param;
    while (std::getline(stream, param, ' ')) {
        // Assuming parameters might not be key-value pairs in this context but a list
        // of arguments for certain commands like "Withdraw" or "Deposit"
        auto pos = param.find('=');
        if (pos != std::string::npos) {
            cmd.parameters[param.substr(0, pos)] = param.substr(pos + 1);
        }
    }

    return cmd;
}
