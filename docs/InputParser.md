# Banking System Commands

This document outlines the commands supported by the banking system, detailing their purposes, parameters, and outcomes.

## Commands
### Create Account

- Format: <User ID> Create <Initial Deposit Amount>
- Purpose: Opens a new bank account with an optional initial deposit.
- Example: A342131 Create 40
- Outcome: A new bank account is opened for the user with the specified ID, and an initial deposit is made if specified.

### Close Account

- Format: <User ID> Close
- Purpose: Closes the user's bank account.
- Example: A342131 Close
- Outcome: The specified bank account is closed, and any remaining balance is returned to the user.

### Deposit

- Format: <User ID> Deposit <Amount>
- Purpose: Deposits the specified amount into the user's bank account.
- Example: A382131 Deposit 10
- Outcome: The specified amount is added to the user's account balance.

### Withdraw

- Format: <User ID> Withdraw <Amount>
- Purpose: Withdraws the specified amount from the user's bank account.
- Example: A332131 Withdraw 40
- Outcome: The specified amount is deducted from the user's account balance if sufficient funds are available.

### Inquiry

- Format: <User ID> Inquiry
- Purpose: Checks the current balance of the user's bank account.
- Example: A342131 Inquiry
- Outcome: The current balance of the user's account is displayed.

### Transfer

- Format: <User ID> Transfer <Amount> <Recipient User ID>
- Purpose: Transfers the specified amount from the user's bank account to another user's bank account.
- Example: A342131 Transfer 40 A382131
- Outcome: The specified amount is transferred from the sender's account to the recipient's account if sufficient funds are available.

Each command begins with the User ID associated with the account to perform the operation on, followed by the command, and then any arguments needed for that command.