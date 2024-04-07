/*
Author: Thomas Kidd
Name: Input Parser
Date written: 04/07/2024
Updated:
    - By: Thomas Kidd on 04/07/2023
*/
#ifndef INPUTPARSER_H
#define INPUTPARSER_H

#include <string>
#include <queue>
#include <map>

// Define a simple structure for commands
struct Command {
    std::string type; // Type of the command (e.g., "CREATE_ACCOUNT", "ADD_PRODUCT")
    std::map<std::string, std::string> parameters; // Key-value pairs for command parameters
};

class InputParser {
public:
    // Constructor
    InputParser() = default;

    // Prevent copying and assignment
    InputParser(const InputParser&) = delete;
    InputParser& operator=(const InputParser&) = delete;

    // Load and parse the file at the given filePath
    bool loadAndParse(const std::string& filePath);

    // Retrieve the next command from the queue
    // Returns false if the queue is empty
    bool getNextCommand(Command& command);

private:
    std::queue<Command> commandQueue; // Queue to store parsed commands

    // Utility function to parse a single line into a Command struct
    Command parseLine(const std::string& line);
};

#endif // INPUTPARSER_H
