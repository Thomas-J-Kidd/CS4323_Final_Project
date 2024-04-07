#ifndef PROCESSMANAGER_H
#define PROCESSMANAGER_H

#include "InputParser.h"
// Assuming InterProcessComs and SynchronizationMonitor are defined elsewhere
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
    // std::shared_ptr<InterProcessComs> ipcManager;
    // std::shared_ptr<SynchronizationMonitor> syncMonitor;

    std::map<std::string, std::function<bool(const Command&)>> commandProcessors;

    // Command processing functions
    bool processCreateAccount(const Command& cmd);
    bool processDeleteAccount(const Command& cmd);
    bool processPlaceItemInCart(const Command& cmd);
    bool processTakeItemOutOfCart(const Command& cmd);
    bool processPurchaseCart(const Command& cmd);
    bool processDeleteCart(const Command& cmd);
    bool processLeaveReview(const Command& cmd);
    bool processReturnItem(const Command& cmd);
    bool processFileComplaint(const Command& cmd);

    // Helper function to set up command processors
    void setupCommandProcessors();
};

#endif // PROCESSMANAGER_H
