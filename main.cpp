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

// include STL header files
#include <iostream>
#include <vector>
#include <string>
#include <memory> // necessary for dynamic memory allocation
#include <iomanip>

using namespace std;

// FUNCTION PROTOTYPES
void displayHeaders();
void displayItemInfo(Inventory, int);
void displayItemInfo(Product);
void displayMenu();
Product getProduct(Product);
void showInventory(vector<Product>);

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
            cout << "+" << setfill('_') << setw(48) << "" << "+" << endl;

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


// FUNCTION DECLARATION
void displayHeaders()
{
    // Format output
    cout << "+" << setfill('-') << setw(48) << "-+" << endl;

    // Display headers with ID, Name, Price and Quantity
    cout << "|" << setfill(' ') << "\t" << left <<  setw(5)  << "ID"
         << left << setw(15)  << "Name"
         << left << setw(10)  << "Price"
         << left << setw(10)  << "Quantity\t|" << endl;
}

//*********************************************************
// This function displays a single item's details such as *
// its ID, name, price and quantity in stock              *
//*********************************************************
void displayItemInfo(Inventory inventory, int product_id)
{
    // Retrieve the item from inventory using product_id
    Product item;

    // Return struct for item with given id
    item = inventory.getItem(product_id);

    cout << "+" << setfill('-') << setw(48) << "+" << endl;

    // Display Item retrieved by product id
    cout << "|" << left << setfill(' ') << "\t" <<  setw(5)  << item.product_id
         << left << setw(15)  << toTitleCase(item.name)
         << "$" <<  left << setw(10) << fixed << setprecision(2) << item.price // Set precision for floating point numbers
         << left << setw(5)  << item.quantity << "\t|" << endl;

    cout << "+" << setfill('_') << setw(48) << "+" << endl;

}

void displayItemInfo(Product item)
{
    cout << "+" << setfill('-') << setw(48) << "+" << endl;

    // Display Item retrieved by product id
    cout << "|" << left << setfill(' ') << "\t" <<  setw(5)  << item.product_id
         << left << setw(15)  << toTitleCase(item.name)
         << "$" <<  left << setw(10) << fixed << setprecision(2) << item.price // Set precision for floating point numbers
         << left << setw(5)  << item.quantity << "\t|" << endl;

}

//*********************************************************
// This function displays the user interface menu for     *
// interacting with the inventory program.                *
//*********************************************************
void displayMenu()
{
    cout << "\t\tINVENTORY PROGRAM" << endl;
    cout << "\n\t(1) Add an item to the inventory." << endl;
    cout << "\t(2) Display information for an item." << endl;
    cout << "\t(3) Remove an item from inventory." << endl;
    cout << "\t(4) Display all items in inventory." << endl;
    cout << "\nPlease select a menu option: ";
}


//*********************************************************
// This function gets the item information from the user  *
// such as ID, Name, Price and Quantity, and returns it as*
// a Product struct.                                      *
//*********************************************************
Product getProduct(Product itemToAdd){
    // ADD AN ITEM
    cout << "Item ID: ";
    cin >> itemToAdd.product_id;

    cout << "Item Name: ";
    cin >> itemToAdd.name;

    cout << "Item Price: ";
    cin >> itemToAdd.price;

    cout << "Quantity in Stock: ";
    cin >> itemToAdd.quantity;

    return itemToAdd;
}

//*********************************************************
// This function formats and displays all the items in the*
// inventory.                                             *
//*********************************************************
void showInventory(vector<Product> allItems)
{
    // // Display headers with ID, Name, Price and Quantity
    // cout << setw(5) << "ID"
    //      << setw(15) << "Name"
    //      << setw(10) << "Price"
    //      << setw(10) << "Quantity" << endl;


    for (const Product &item : allItems)
    // Display the items stored in the vector allItems
    {
    // cout << setw(5) << item.product_id
    //      << setw(15) << item.name
    //      << setw(10) << fixed << setprecision(2) << item.price // Set precision for floating point numbers
    //      << setw(10) << item.quantity << endl;
        displayItemInfo(item);
    }
}
