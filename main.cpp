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
void displayItemInfo(Product);
void displayDefaultItem(Product itemToFind);
void displayMenu();
Product getProduct(Product);
void showInventory(vector<Product>);
void showInventoryCount(Inventory);

int main(){
    // initialize class with default item as example
    Product defaultItem = {1, "Default Item", 9.99, 10};
    Inventory inventory(defaultItem);
    Product item2 = {2, "Item 2", 10.00, 12};

    // Dynammically allocate a pointer to an inventory obj
    // Inventory *invPtr = nullptr;
    // invPtr = new Inventory(defaultItem);

    // smart pointer
    // unique_ptr<vector<Product>> inventory(new vector<Product>());

    // adding elements to inventory
    // inventory->push_back({2, "Knife", 34.99, 5});

    Product itemToAdd;
    vector<Product> allItems;
    Product itemToFind, itemToRemove;
    int itemID, menuChoice;
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
            cout << "\t\tADD AN ITEM" << endl;


            // ADD ITEM TO INVENTORY
            itemToAdd = getProduct(itemToAdd); // get product info from user
            inventory.addItem(itemToAdd); // add product to inventory

            break;
        case 2:
            cout << "You selected option 2." << endl;
            break;
        case 3:
            cout << "You selected option 3." << endl;
            break;
        case 4:
            // LIST ALL INVENTORY
            showInventoryCount(inventory);

            // Returns a vector of Product structs with each item
            allItems = inventory.getAllItems(); 

            // Show all items to user
            showInventory(allItems);

            break;
        }


        // REPEAT LOOP
        cout << "Return to the main menu? (Y/N): ";
        cin >> input;
    } while (tolower(input) == 'y');

    cout << "Thanks for using the inventory program!" << endl;


    // LIST ALL INVENTORY
    // See all items in inventory
    // allItems = inventory.getAllItems();

    // cout << "The following items are currently held in inventory: " << endl;
    // cout << "Item Name: " << endl;
    // for (const Product &item : allItems)
    // {
    //     cout << "    " << setw(20) << left 
    //          << toTitleCase(item.name) 
    //          << endl;
    // }

    // GET AN ITEM & DESCRIPTION
    // get item: encompass it in a try/except block to account for NotFound error

    // DISPLAY DEFAULT ITEM
    // itemToFind = inventory.getItem(1);
    // displayDefaultItem(itemToFind);

    // add item
    // inventory.addItem(item2);

    // display total items
    // itemCount = inventory.getItemCount();
    // cout << "Total items in inventory: " << itemCount << endl;

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

//*********************************************************
// This function displays a single item's details such as *
// its ID, name, price and quantity in stock              *
//*********************************************************
void displayItemInfo(Product item)
{
        cout << "Product ID: " << item.product_id << endl
        << "Name: " << toTitleCase(item.name) << endl
        << "Price: $" << setprecision(2) << fixed << item.price << endl
        << "Quantity: " << item.quantity << " in stock." << endl;
}

//*********************************************************
// This function displays the default item for user to get*
// an idea of the data to input for an item in inventory. *
//*********************************************************

void displayDefaultItem(Product itemToFind)
{
    try{
        cout << "Reference the default item example for the data to enter: " << endl;
        displayItemInfo(itemToFind);
    }
    catch (const exception& e){
        cerr << "Error! " << e.what() << endl;
    }
}

//*********************************************************
// This function displays the user interface menu for     *
// interacting with the inventory program.                *
//*********************************************************
void displayMenu()
{
    cout << "\t\tINVENTORY PROGRAM" << endl;
    cout << "(1) Add an item to the inventory." << endl;
    cout << "(2) Remove an item from inventory." << endl;
    cout << "(3) Display information for an item." << endl;
    cout << "(4) Display all items in inventory." << endl;
    cout << "Please select a menu option: ";
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
    cout << "The following items are currently held in inventory: " << endl;

    // Display headers with ID, Name, Price and Quantity
    cout << setw(5) << "ID"
         << setw(15) << "Name"
         << setw(10) << "Price"
         << setw(10) << "Quantity" << endl;


    for (const Product &item : allItems)
    // Display the items stored in the vector allItems
    {
    cout << setw(5) << item.product_id
         << setw(15) << item.name
         << setw(10) << fixed << setprecision(2) << item.price // Set precision for floating point numbers
         << setw(10) << item.quantity << endl;
    }
}

//*********************************************************
// This function displays the total items in inventory    *
// and formats the message differently depending on the   *
// total.                                                 *
//*********************************************************
void showInventoryCount(Inventory inventory)
{
    // Display the total items in inventory using static member variable
    int itemCount;
    itemCount = inventory.getItemCount();

    // Handle different cases
    if(itemCount > 1)
        cout << "There are currently " << itemCount << " items in inventory." << endl;
    else if(itemCount == 1)
        cout << "There is currently only " << itemCount << " item in inventory." << endl;
    else
        cout << "There are currently no items in inventory." << endl;

}