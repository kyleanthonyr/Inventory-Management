#include "Inventory.hpp"
#include "Product.hpp"
// #include "utilities.cpp"
#include <vector>
#include <iostream>
#include <cctype>
#include <exception>
#include <algorithm>
#include <string>

using namespace std;

//*********************************************************
// This utility function converts a string to title case  *
// and returns the modified string value.                 *
// Used for whenever item name is outputted to console    *
//*********************************************************
string toTitleCase(string itemName)
{
    // save item name in local variable
    string name = itemName;

    // Convert to title case
    if(!name.empty())
        name[0] = toupper(name[0]);

    return name;
}

//*********************************************************
// The constructor initializes the allItems vector of     *
// Products and accepts a default item of Product datatype*
// It also increments the static member variable itemsCount
// to keep track of the total items in inventory          *
//*********************************************************
Inventory::Inventory() {};

//*********************************************************
// This accessor function retrieves the total items stored*
// in the inventory held by the static member variable    *
// itemsCount.
//*********************************************************
int Inventory::getItemCount() const
{
    return itemsCount;
}

//*********************************************************
// This member function of the Inventory class adds an    *
// item based on the item's product ID.                   *
// The item is of the Product struct data type.           *
//*********************************************************
void Inventory::addItem(Product item)
{
    // Add a new item to the inventory
    allItems.push_back(item);

    // increment the total items in inventory
    Inventory::itemsCount++;
}


//*********************************************************
// This member function of the Inventory class removes an *
// item based on the item's product ID.                   *
// The item is of the Product struct data type.           *
//*********************************************************
Product Inventory::removeItem(int productID)
{
    // Loops through the items in the inventory object
    for(int i = 0; i < allItems.size(); i++)
    {
        // Finds the item with the matching product ID arg
        if(allItems[i].product_id == productID)
        {
            // removes the element found at the index
            allItems.erase(allItems.begin()+i);

            // Decrement itemsCount static member variable
            if(itemsCount == 0)
            {
                cout << "There are no items to remove!" << endl;
            } else
            {
                itemsCount--;
            }

            // returns the item that was removed
            return allItems[i];
        }
    }
    
    // throw an error if the element was not found
    throw runtime_error("No product with that ID was found! Try again."); 

}

//*********************************************************
// This member function of the Inventory class displays   *
// info about a specific item. It uses the product ID to  *
// find the item.                                         *
// The item is of the Product struct data type.           *
//*********************************************************
Product Inventory::getItem(int productID) const
{
    // loops through the items in the Inventory object
    for(Product item: allItems){
        // returns the item with corresponding product ID
        if (item.product_id == productID)
            return item;
    }
    
    // throws an error if the element was not found
    throw runtime_error("No product with that ID was found! Try again."); 

}

//*********************************************************
// This member function of the Inventory class displays   *
// all of the item names stored in the inventory.         *
// It returns a vector of the Product struct data type to *
// be iterated over for display                           *
//*********************************************************
vector<Product> Inventory::getAllItems() const
{
    return allItems;
}