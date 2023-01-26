#include "Cart.h"
#include <iostream>
#include <iomanip>

// Adds Item given the items product code
void Cart::addItem( std::string productCode ) {
    bool exists = false;
    bool inCart = false;
    // Checks to see if the item is already in the cart and increments its quantity if it is.
    for (auto& item : cart) {
        if (productCode == item.productCode) {
            inCart = true;
            item.quantity++;
            exists = true;
        }
    }
    // Adds the item to the cart if its not already there
    if (!inCart) {
        for (auto& item : catalog) {
            if (item.code == productCode) {
                CartItem newItem {item.name, item.code, item.price, 1};
                cart.push_back(newItem);
                exists = true;
            }
        }
    }
    // Throws an error if an invalid product code was given
    if (!exists)
        throw std::out_of_range("Product code does not match existing product.");
}

// Calculates the total cost of the items in the cart
void Cart::calculateTotal( ) {
    
    // Adds up the cost of items
    for (auto& item : cart) {
        this->total += item.price * item.quantity;
        // Checks to make sure there are no available discounts
        for (auto& offer : offers) {
            if (item.productCode == offer.productCode && item.quantity >= offer.quantReq) {
                this->discount = item.price * offer.discount;
                this->total -= this->discount;
            }
        }
    }
    // Calculates cost of shipping based on total
    int shippingIndex = 0;
    while (total >= std::get<0>(shippingPrices[shippingIndex]) && shippingIndex < shippingPrices.size()) {
        shippingIndex++;
    }
    this->shipping = std::get<1>(shippingPrices[shippingIndex]);
    this->total += shipping;
}

void Cart::printCatalog( ) {
    for (auto& item : catalog) {
        std::cout << item.name << "(" << item.code << "): " << item.price << std::endl;
    }
}

void Cart::printCart( ) {
    calculateTotal( );
    for (auto& item : cart) {
        std::cout << item.name << " | " << item.price << " * " << item.quantity << std::endl;
    }
    std::cout << std::fixed << std::setprecision(2) << "Discount: -" << this->discount << std::endl
              << std::fixed << std::setprecision(2) << "Shipping: " << this->shipping << std::endl            
              << std::fixed << std::setprecision(2) << "TOTAL: " << this->total << std::endl;
}
