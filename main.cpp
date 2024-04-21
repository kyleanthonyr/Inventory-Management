// Author: Kyle Rodriguez
// Date: April 6th, 2024
// COSC1437 - Dr. Nina Javaher

/*
Implement a menu-driven program that allows the user to 
interact with the inventory system. The menu should include 
options to add, remove, display information, and display the 
entire inventory. Once the user is done with one menu option, 
the program should ask if they want to run another menu option 
or if they want to quit.

You need to demonstrates the use of a struct (product) to 
represent individual products and a class (inventory) to manage 
the overall inventory system. 
*/

// include header files and function file
#include "Product.hpp"
#include "Inventory.hpp"
#include "inventory.cpp"
#include "utilities.cpp"

// include STL header files
#include <iostream>
#include <vector>
#include <string>
#include <memory> // necessary for dynamic memory allocation
#include <iomanip>

using namespace std;

int main(){
    // VARIABLES
    Inventory inventory; // instance of inventory class

    Product item;
    vector<Product> allItems; // vector of Products containing items in inventory
    Product itemToFind, itemToRemove;
    int item_id, menuChoice, itemCount;
    char input;

    // Create interactive menu session for user
    do
    {
        // DISPLAY MENU AND GET INPUT
        displayMenu();
        cin >> menuChoice;

        // USER CHOICE INPUT VALIDATION
        // Handles if the user input was not an int, or was less than 1 and greater than 4
        while (!menuChoice || menuChoice < 1 || menuChoice > 4)
        {
            cout << "Please select a valid option from the menu." << endl;
            cin.clear(); // clears any error flags
            cin.ignore(20, '\n'); // clears input buffer
            cin >> menuChoice;
        }

        // HANDLE USER CHOICE with SWITCH 
        switch (menuChoice)
        {
        case 1: // ADD ITEM TO INVENTORY
            // USER INTERFACE
            cout << endl;
            cout << setfill('-') << setw(50) << "" << endl;
            cout << "\n\t\t   ADD AN ITEM" << endl;

            // Add item
            item = getProduct(item); // get product info from user
            inventory.addItem(item); // add product to inventory

            // Display added item
            cout << endl;
            displayHeaders();
            displayItemInfo(item);
            cout << "+" << setfill('-') << setw(47) << "" << "+" << endl;

            // Output message indicating new item has been added to inventory
            cout << endl;
            cout << toTitleCase(item.name) 
                << " has been added to the inventory!" << endl;
            cout << endl;

            break;
        case 2: // DISPLAY ITEM INFO
            // USER PROMPT
            // Prompts user for product ID to be found
            cout << setfill('-') << setw(50) << "" << endl;
            cout << "\n\t\t   DISPLAY INFO\n";
            cout << endl;
            cout << "Enter the Product ID: ";
            cin >> item_id;
            cout << endl;

            // INPUT VALIDATION
            // Ensures input is of type int
            while(!item_id)
            {
                cout << "Please input a valid numeric Product ID: ";
                cin.clear();
                cin.ignore(20, '\n');
                cin >> item_id;
            }

            // GET ITEM FROM INVENTORY
            // Tries to get item from inventory using product ID
            // Throws an error if ID is not found
            try
            {
                // DISPLAY INFO
                displayHeaders();
                displayItemInfo(inventory, item_id);
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';

            }

            break;

        case 3: // REMOVE AN ITEM
            // remove the element from the vector based on provided ID
            cout << setfill('-') << setw(50) << "" << endl;
            cout << "\n\t\t   REMOVE AN ITEM" << endl;
            cout << "\nEnter the product ID to remove: ";
            cin >> item_id;

            try
            {
                item = inventory.removeItem(item_id);
                cout << endl;
                cout << toTitleCase(item.name) << " was removed from inventory!" << endl;
                displayItemInfo(item);
                cout << "+" << setfill('-') << setw(47) << ""
                     << "+" << endl;
                cout << endl;
            }
            catch(const exception& e){
                cerr << "Error! " << e.what() << endl;
            }
            break;

        case 4: // DISPLAY ALL INVENTORY
            cout << setfill('-') << setw(50) << "" << endl;
            cout << "\n\t\t   ALL INVENTORY\n";

            // Returns a vector of Product structs with each item
            allItems = inventory.getAllItems(); 

            // Show all items to user
            cout << "\nThe following items are currently held in inventory: " << endl;
            displayHeaders();
            showInventory(allItems);
            cout << "+" << setfill('-') << setw(47) << "" << "+" << endl;

            // Give the count of total items in inventory
            itemCount = inventory.getItemCount();
            cout << "Total Items: " << itemCount << endl;
            cout << endl;

            break;
        }


        // REPEAT LOOP
        cout << "Return to the main menu? (Y/N): ";
        cin >> input;
        cout << endl;
        cout << setfill('-') << setw(49) << "-" << endl;
        cout << endl;

    } while (tolower(input) == 'y');

    cout << "Thanks for using the inventory program!" << endl;

    return 0;
}
