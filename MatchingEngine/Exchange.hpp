//
//  Exchange.hpp
//  MatchingEngine
//
//  Created by Shane Carey on 9/13/15.
//  Copyright © 2015 Shane Carey. All rights reserved.
//

#ifndef Exchange_cpp
#define Exchange_cpp

#include <unordered_map>

#include "Order.hpp"
#include "Commodity.hpp"

class Exchange {
public:
    Exchange();
    
    ~Exchange();
    
    void match(Order *order);
    
private:
    std::unordered_map<std::string, Commodity *> commodities;
};

#endif /* Exchange_cpp */
