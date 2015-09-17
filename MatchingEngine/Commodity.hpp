//
//  Commodity.hpp
//  MatchingEngine
//
//  Created by Shane Carey on 9/13/15.
//  Copyright © 2015 Shane Carey. All rights reserved.
//

#ifndef Commodity_cpp
#define Commodity_cpp

#include <unordered_map>
#include <queue>

#include "Order.hpp"

class Commodity {
public:
    Commodity();
    
    ~Commodity();
    
    void match(Order *inOrder);
    
private:
    // Priority queues of ids to orders, hold best time/price at top
    std::priority_queue<Order *, std::vector<Order *>, Order> buyQueue;
    std::priority_queue<Order *, std::vector<Order *>, Order> sellQueue;
    
    // Hash map to each order, by id
    std::unordered_map<int, Order *> ordersBook;
    std::unordered_map<int, Order *> cancelledOrdersBook;
    
    void reduceOrderBook();
    
    void handleOrder(Order *order);
    
    void handleCancel(Order *cancel);
    
    void handleReplace(Order *replace);
};


#endif /* Commodity_cpp */
