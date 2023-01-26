#include "Cart.h"
#include<iostream>

int main() {
    Cart cart;
    cart.printCatalog( );

    std::string input;
    do {
        std::cout << "Enter the product code for products you want one at a time (Enter -1 to quit): ";
        std::cin >> input;
        if(input != "-1") 
            cart.addItem(input);
    } while (input != "-1");

    cart.printCart( );
    return 0;
}