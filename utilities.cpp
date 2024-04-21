// HEADER FILES
#include "Inventory.hpp"
#include "Product.hpp"

// STL LIBRARY
#include <vector>
#include <iostream>
#include <cctype>
#include <exception>
#include <algorithm>
#include <string>
#include <iomanip>

using namespace std;

// FUNCTION DECLARATION
void displayHeaders()
{
    // Format output
    cout << "+" << setfill('-') << setw(47) << "" << "+" << endl;


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

    cout << "+" << setfill('-') << setw(47) << "" << "+" << endl;


    // Display Item retrieved by product id
    cout << "|" << left << setfill(' ') << "\t" <<  setw(5)  << item.product_id
         << left << setw(15)  << toTitleCase(item.name)
         << "$" <<  left << setw(10) << fixed << setprecision(2) << item.price // Set precision for floating point numbers
         << left << setw(5)  << item.quantity << "\t|" << endl;

    cout << "+" << setfill('-') << setw(47) << "" << "+" << endl;


}

void displayItemInfo(Product item)
{
    cout << "+" << setfill('-') << setw(47) << "" << "+" << endl;

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
