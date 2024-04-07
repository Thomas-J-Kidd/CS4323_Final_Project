#include "InputParser.h"
#include "ProcessManager.h" // Include the ProcessManager
#include <iostream>

int main() {
    InputParser parser;
    ProcessManager processManager; // Create an instance of ProcessManager

    // Assuming the ProcessManager's initialize method sets up necessary components
    // and command processors. If initialization requires more (like setting up IPC 
    // or synchronization components), make sure to include those steps before processing commands.
    processManager.initialize(); 

    if (!parser.loadAndParse("../text-files/commands.txt")) {
        std::cerr << "Failed to load or parse commands." << std::endl;
        return 1;
    }

    // Use ProcessManager to process the commands instead of directly handling them here.
    processManager.processCommands(parser);

    return 0;
}
