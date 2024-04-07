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
        // Ensure the command type is not empty, indicating a successfully parsed line
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
    std::string segment;
    std::getline(stream, cmd.type, ' '); // Extract the command type until the first space

    // Parse the rest of the line for key=value pairs
    while (std::getline(stream, segment, ' ')) {
        std::string key, value;
        std::istringstream segmentStream(segment);
        if (std::getline(std::getline(segmentStream, key, '='), value)) {
            cmd.parameters[key] = value;
        }
    }

    return cmd;
}
