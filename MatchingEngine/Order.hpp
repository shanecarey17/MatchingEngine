//
//  Order.hpp
//  MatchingEngine
//
//  Created by Shane Carey on 9/13/15.
//  Copyright © 2015 Shane Carey. All rights reserved.
//

#ifndef Order_cpp
#define Order_cpp

#include <string>

class Order {
public:
    std::string type;
    int id;
    std::string symbol;
    std::string side;
    int quantity;
    float price;
    bool active; // flag for cancelled order
    
    Order();
    
    // Comparator
    bool operator()(Order *order1, Order *order2);
};

#endif /* Order_cpp */
