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

int main(){
    // variable definition
    Inventory inventory;
    Product itemToAdd;
    vector<Product> allItems;
    Product itemToFind, itemToRemove;
    int itemID;

    // ADD AN ITEM
    cout << "Enter an id: " << endl;
    cin >> itemToAdd.product_id;

    cout << "Enter a name: " << endl;
    cin >> itemToAdd.name;

    cout << "Enter a price: " << endl;
    cin >> itemToAdd.price;

    cout << "Enter the quantity in stock: " << endl;
    cin >> itemToAdd.quantity;



    // Add item to the inventory
    inventory.addItem(itemToAdd);


    // LIST ALL INVENTORY
    // See all items in inventory
    allItems = inventory.getAllItems();

    cout << "The following items are currently held in inventory: " << endl;
    for (const Product& item : allItems)
    {
        cout << left << setw(15) << toTitleCase(item.name) << endl;
    }

    // // GET AN ITEM & DESCRIPTION
    // // get item: encompass it in a try/except block to account for NotFound error
    // cout << "Enter the product ID to return: " << endl;
    // cin >> itemID;

    // try{
    //     itemToFind = inventory.getItem(itemID);
    //     displayItemInfo(itemToFind);
    // }
    // catch (const exception& e){
    //     cerr << "Error! " << e.what() << endl;
    // }

    // REMOVE AN ITEM
    // remove the element from the vector based on provided ID
    cout << "Enter the product ID to remove: " << endl;
    cin >> itemID;

    try
    {
        itemToRemove = inventory.removeItem(itemID);
        cout << "The following item was removed from the inventory!" << endl;
        displayItemInfo(itemToRemove);
    }
    catch(const exception& e){
        cerr << "Error! " << e.what() << endl;
    }

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

