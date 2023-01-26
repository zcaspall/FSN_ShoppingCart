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
    // hardcoded the catalog
    std::vector<Product> catalog {{"Red FLower", "RF1", 32.95},
                                  {"Green Flower", "GF1", 24.95},
                                  {"Blue Flower", "BF1", 7.95}};
    // allows you to add as many or as few shipping prices as needed
    std::vector< std::pair<double, double>> shippingPrices {{50.0, 4.95}, {90.0, 2.95}};
    // allows you to edit or add different discounts based on product codes
    std::vector<Offer> offers {{"RF1", .5, 2}};
    std::vector<CartItem> cart;
    double total = 0;
    double shipping = 0;
    double discount = 0;
};

#endif
