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
    // initialize class with default item as example
    Inventory inventory;

    Product itemToAdd;
    vector<Product> allItems;
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
        case 1:
            // USER INTERFACE
            cout << setfill('-') << setw(50) << "" << endl;
            cout << "\n\t\tADD AN ITEM" << endl;

            // ADD ITEM TO INVENTORY
            itemToAdd = getProduct(itemToAdd); // get product info from user
            inventory.addItem(itemToAdd); // add product to inventory

            break;
        case 2:
            // USER PROMPT
            // Prompts user for product ID to be found
            cout << "Enter the Product ID: ";
            cin >> item_id;

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
                cout << "\t\tDISPLAY INFO\n";
                displayHeaders();
                displayItemInfo(inventory, item_id);
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';

            }

            break;

        case 3:
            cout << "You selected option 3." << endl;
            break;

        case 4:
            cout << "\t\tALL INVENTORY\n";

            // Returns a vector of Product structs with each item
            allItems = inventory.getAllItems(); 

            // Show all items to user
            cout << "The following items are currently held in inventory: " << endl;
            displayHeaders();
            showInventory(allItems);
            cout << "+" << setfill('-') << setw(47) << "" << "+" << endl;

            // Give the count of total items in inventory
            itemCount = inventory.getItemCount();
            cout << "Total Items: " << itemCount << endl;

            break;
        }


        // REPEAT LOOP
        cout << "Return to the main menu? (Y/N): ";
        cin >> input;
    } while (tolower(input) == 'y');

    cout << "Thanks for using the inventory program!" << endl;

    // // REMOVE AN ITEM
    // // remove the element from the vector based on provided ID
    // cout << "Enter the product ID to remove: " << endl;
    // cin >> itemID;

    // try
    // {
    //     itemToRemove = inventory.removeItem(itemID);
    //     cout << "The following item was removed from the inventory!" << endl;
    //     displayItemInfo(itemToRemove);
    // }
    // catch(const exception& e){
    //     cerr << "Error! " << e.what() << endl;
    // }

    return 0;
}
