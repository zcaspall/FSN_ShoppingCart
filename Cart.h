#ifndef CART_H
#define CART_H

#include<vector>
#include<string>
#include<utility>
#include "CartItem.h"
#include "Product.h"
#include "Offer.h"

class Cart {
public:
    Cart( ) = default;
    void addItem( std::string productCode );
    void printCatalog( );
    void printCart( );
private:
    void calculateTotal( ); 
    std::vector<Product> catalog {{"Red FLower", "RF1", 32.95},
                                  {"Green Flower", "GF1", 24.95},
                                  {"Blue Flower", "BF1", 7.95}};
    std::vector< std::pair<double, double>> shippingPrices {{50.0, 4.95}, {90.0, 2.95}};
    std::vector<Offer> offers {{"RF1", .5, 2}};
    std::vector<CartItem> cart;
    double total = 0;
    double shipping = 0;
    double discount = 0;
};

#endif