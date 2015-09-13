//
//  Exchange.cpp
//  MatchingEngine
//
//  Created by Shane Carey on 9/13/15.
//  Copyright © 2015 Shane Carey. All rights reserved.
//

#include "Exchange.hpp"

Exchange::Exchange() {
    commodities = std::unordered_map<std::string, Commodity *>();
};

void Exchange::match(Order *order) {
    if (commodities[order->symbol] == NULL) {
        commodities[order->symbol] = new Commodity();
    }
    
    commodities[order->symbol]->match(order);
}

Exchange::~Exchange() {
    for (std::unordered_map<std::string, Commodity *>::iterator it = commodities.begin(); it != commodities.end(); it++) {
        delete it->second;
    }
}
