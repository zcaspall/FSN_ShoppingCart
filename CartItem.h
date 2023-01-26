#ifndef CARTITEM_H
#define CARTITEM_H

struct CartItem {
    std::string name;
    std::string productCode;
    double      price;
    int         quantity;
};

#endif