// Author: Kyle Rodriguez
// Date: April 6th, 2024
// COSC1437 - Dr. Nina Javaher

// This header file contains the code that defines an Inventory
// object and it's corresponding attributes and member functions

#ifndef INVENTORY_H
#define INVENTORY_H
#include "Product.hpp" // brings in the code for the Product struct
#include <memory>
#include <vector>
#include <string>

using namespace std;


class Inventory
{
    private:
        // Store all items in a vector of Product objects
        vector<Product> allItems;

        // Get a count of all items in the inventory
        static int itemsCount;

    public:
        // Constructor to accept default argument
        Inventory();

        // Accessor function to get inventory count
        int getItemCount() const;

        // Member function to add an item to the inventory
        void addItem(Product item);

        // Member function to remove an item from inventory
        Product removeItem(int productID);

        // Display info about a specific product
        Product getItem(int productID) const;

        // Display entire inventory of products
        vector<Product> getAllItems() const;
};

// Definition of static member variable itemsCount
int Inventory::itemsCount = 0;

#endif