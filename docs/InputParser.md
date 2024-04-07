# E-Commerce System Commands

This document outlines the commands supported by the e-commerce system, detailing their purposes, required parameters, and outcomes.

## Commands

### CREATE_ACCOUNT

- **Purpose**: Registers a new user account.
- **Parameters**:
  - `username`: Unique identifier for the user.
  - `email`: User's email address.
  - `password`: User's password.
- **Outcome**: A new user account is created, and user details are stored.

### DELETE_ACCOUNT

- **Purpose**: Removes an existing user account.
- **Parameters**:
  - `username`: Unique identifier for the user.
- **Outcome**: The specified user account is deleted along with all associated data.

### PLACE_ITEM_IN_CART

- **Purpose**: Adds a specified item to the user's shopping cart.
- **Parameters**:
  - `username`: Unique identifier for the user.
  - `product_id`: Unique identifier for the product.
  - `quantity`: Number of items to add.
- **Outcome**: The specified item is added to the user's cart in the specified quantity.

### TAKE_ITEM_OUT_OF_CART

- **Purpose**: Removes a specified item from the user's shopping cart.
- **Parameters**:
  - `username`: Unique identifier for the user.
  - `product_id`: Unique identifier for the product.
  - `quantity`: Number of items to add.
- **Outcome**: The specified item is removed from the user's cart.

### PURCHASE_CART

- **Purpose**: Processes all items in the user's shopping cart as a single purchase.
- **Parameters**:
  - `username`: Unique identifier for the user.
- **Outcome**: The purchase is finalized, inventory is updated, and an order receipt is generated.

### DELETE_CART

- **Purpose**: Clears all items from the user's shopping cart.
- **Parameters**:
  - `username`: Unique identifier for the user.
- **Outcome**: The user's cart is emptied.

### LEAVE_REVIEW

- **Purpose**: Allows a user to leave a review on a purchased item.
- **Parameters**:
  - `username`: Unique identifier for the user.
  - `product_id`: Unique identifier for the product.
  - `rating`: Numeric rating for the product.
  - `comment`: Optional textual review of the product.
- **Outcome**: The review is associated with the product and is visible to other users.

### RETURN_ITEM

- **Purpose**: Initiates a return process for an item the user previously purchased.
- **Parameters**:
  - `username`: Unique identifier for the user.
  - `order_id`: Unique identifier for the order containing the item.
  - `product_id`: Unique identifier for the product being returned.
- **Outcome**: The return is processed, and the user is refunded.

### FILE_COMPLAINT

- **Purpose**: Submits a complaint related to an order, product, or service.
- **Parameters**:
  - `username`: Unique identifier for the user.
  - `order_id`: Unique identifier for the order, if applicable.
  - `complaint`: Textual description of the complaint.
- **Outcome**: The complaint is logged and flagged for review by customer service.
