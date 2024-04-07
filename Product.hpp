// Author: Kyle Rodriguez
// Date: April 6th, 2024
// COSC1437 - Dr. Nina Javaher

// This header file contains the code that defines the Product struct
// for use in the Inventory class
#include <string>
using namespace std;

#ifndef PRODUCT_H
#define PRODUCT_H

struct Product
{
    int product_id; // a unique id for each product
    string name; // the name of a product
    double price; // the price of a product
    int quantity; // the quantity in stock
};

#endif