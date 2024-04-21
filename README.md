# Inventory Management System

**Purpose:**

A command line menu-driven program that allows the user to interact with an inventory management system.

The menu includes options to add, remove, and display information about an item in inventory, as well as display the entire inventory.

The user is prompted to run another menu option after each selection is completed to offer an interactive session.

**Technical Details:**

The program is built with OOP in mind. It makes use of an `Inventory` class and `Product` struct to store and manage items received from users for inventory.

Each item is stored as an instance of `Product` which has the following form and is located in `Product.hpp` file:

-   Product ID
-   Name
-   Price
-   Quantity

Utility functions for formatting and storing/managing items are stored in the `utilities.cpp` file while the Inventory class along with its member functions are defined in `Inventory.hpp` and `inventory.cpp` respectively.

## Installation

#### Requirements:

-   Compiler: `g++` for Windows or `clang` for MacOS
-   If using VS Code, the "C/C++" and "C/C++ Extension Pack" extensions should be installed.

See link to configure VS Code for [Windows](https://code.visualstudio.com/docs/cpp/config-mingw) or [MacOS](https://code.visualstudio.com/docs/cpp/config-clang-mac).

After Downloading Files:

```bash
  cd Inventory-Management-main
```

## Badges

[![MIT License](https://img.shields.io/badge/License-MIT-green.svg)](https://choosealicense.com/licenses/mit/)
![C++](https://img.shields.io/badge/Language-C%2B%2B-blue)
![Design](https://img.shields.io/badge/Design-OOP-red)

## Authors

Kyle Rodriguez |
[@Github](https://www.github.com/kyleanthonyr) |
[@LinkedIn](https://www.linkedin.com/in/kyle-a-rodriguez/)
