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
#include <tuple>

using namespace std;

// FUNCTION DECLARATION

//*********************************************************
// This utility function validates the data type of a user*
// input variables like ID, Name, Price and Quantity      *
//*********************************************************
int validate(int num)
{
    while(!num)
    {
        cout << "Please enter a valid integer: ";
        cin.clear(); // clear any error flags
        cin.ignore(20, '\n');
        cin >> num;
    }

    return num; // return the validated integer
}

//*********************************************************
// Helper function checks if input is a string            *
//*********************************************************
bool isString(const string& name)
{
    // checks if string is not a char or space 
    for (const char ch : name)
    {
        // checks if a char is not a space or alphanumeric
        if (!isalpha(ch) && !isspace(ch))
            return false;
    }

    return !name.empty();
}

//*********************************************************
// Overloaded function to validate string input           *
//*********************************************************
string validate(string name)
{
    while(name.empty() || !isString(name))
    {
        cout << "Please enter a valid name: ";
        getline(cin, name);
    }

    return name; // return the validated name
}

//*********************************************************
// Overloaded function to validate double input           *
//*********************************************************
double validate(double price)
{
    while(!price || price < 1)
    {
        cout << "Please enter a valid price: ";
        cin.clear(); // clear any error flags
        cin.ignore(20, '\n');
        cin >> price;
    }

    return price; // return the validated double
}


//*********************************************************
// This function displays the headers for an item such as *
// ID, Name, Price and Quantity.                          *
//*********************************************************
void displayHeaders()
{
    // Format output
    cout << "+" << setfill('-') << setw(47) << "" 
         << "+" << endl;


    // Display headers with ID, Name, Price and Quantity
    cout << "|" << setfill(' ') << "\t" 
         << left <<  setw(5) << "ID"
         << left << setw(15)  << "Name"
         << left << setw(10)  << "Price"
         << left << setw(10)  << "Quantity\t|" << endl;
}

//*********************************************************
// This function displays a single item's details such as *
// its ID, name, price and quantity in stock              *
// Accepts instance of Inventory class and product ID to  *
// display                                                *
//*********************************************************
void displayItemInfo(Inventory inventory, int product_id)
{
    // Retrieve the item from inventory using product_id
    Product item;

    // Return struct for item with given id
    item = inventory.getItem(product_id);

    // User-friendly border around item
    cout << "+" << setfill('-') << setw(47) << "" 
         << "+" << endl;


    // Display Item retrieved by product id
    cout << "|" << left << setfill(' ') << "\t" 
         <<  setw(5) << item.product_id
         << left << setw(15)  << toTitleCase(item.name)
         << "$" <<  left << setw(10) << fixed 
         << setprecision(2) << item.price 
         << left << setw(5)  << item.quantity << "\t|" << endl;

    cout << "+" << setfill('-') << setw(47) << "" << "+" << endl;


}

//*********************************************************
// This is an overloaded version of displayItemInfo()     *
// it takes an instance of struct Product as an argument  *
//*********************************************************
void displayItemInfo(Product item)
{
    cout << "+" << setfill('-') << setw(47) << "" << "+" << endl;

    // Display Item retrieved by product id
    cout << "|" << left << setfill(' ') << "\t" 
         << setw(5) << item.product_id
         << left << setw(15)  << toTitleCase(item.name)
         << "$" <<  left << setw(10) << fixed 
         << setprecision(2) << item.price 
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
// a Product struct. It validates data types as well.     *
//*********************************************************
Product getProductFromUser(Product itemToAdd){
    // LOCAL VARIABLES
    int item_id, quantity;
    string item_name;
    double item_price;

    // VALIDATE USER INPUT AND ADD ID TO STRUCT
    cout << "Item ID: ";
    cin >> item_id;

    // Validate item id
    item_id = validate(item_id);

    // Add validated ID to itemToAdd struct
    itemToAdd.product_id = item_id;



    // VALIDATE USER INPUT AND ADD NAME TO STRUCT
    cout << "Item Name: ";

    // Clear input buffer from previous input
    cin.clear();
    cin.ignore(50, '\n');
    cin.sync();

    getline(cin, item_name);

    // Validate Item Name
    item_name = validate(item_name);

    // Add validated name to itemToAdd struct
    itemToAdd.name = item_name;



    // VALIDATE USER INPUT AND ADD PRICE TO STRUCT
    cout << "Item Price: ";
    cin >> item_price;

    // Validate Item Name
    item_price = validate(item_price);

    // Add validated name to itemToAdd struct
    itemToAdd.price = item_price;



    // VALIDATE USER INPUT AND ADD QUANTITY TO STRUCT
    cout << "Quantity: ";
    cin >> quantity;

    // Validate item id
    quantity = validate(quantity);

    // Add validated ID to Product struct itemToAdd
    itemToAdd.quantity = quantity;


    return itemToAdd;
}

//*********************************************************
// This function formats and displays all the items in the*
// inventory.                                             *
//*********************************************************
void showInventory(vector<Product> allItems)
{
    for (const Product &item : allItems)
    // Display the items stored in the vector allItems
    {
        displayItemInfo(item);
    }
}
