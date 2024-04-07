#ifndef INPUTPARSER_H
#define INPUTPARSER_H

#include <string>
#include <queue>
#include <vector>

// Define a simple structure for commands
struct Command {
    std::string type; // The type of command (e.g., ADD, DELETE)
    std::vector<std::string> parameters; // Parameters of the command
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
