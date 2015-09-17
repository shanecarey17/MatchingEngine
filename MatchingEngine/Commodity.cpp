//
//  Commodity.cpp
//  MatchingEngine
//
//  Created by Shane Carey on 9/13/15.
//  Copyright © 2015 Shane Carey. All rights reserved.
//

#include <iostream>

#include "Commodity.hpp"

void Commodity::match(Order *inOrder) {
    // Handle order, cancel, replace
    if (inOrder->type[0] == 'O') {
        handleOrder(inOrder);
    } else if (inOrder->type[0] == 'C') {
        handleCancel(inOrder);
    } else {
        handleReplace(inOrder);
    }
}

void Commodity::handleOrder(Order *order) {
    ordersBook[order->id] = order;
    if (order->side[0] == 'B') {
        buyQueue.push(order);
    } else {
        sellQueue.push(order);
    }
    
    reduceOrderBook();
};

void Commodity::handleCancel(Order *cancel) {
    // Set order with same id inactive
    Order *toCancel = ordersBook[cancel->id];
    toCancel->active = false;
    ordersBook.erase(cancel->id);
    
    delete cancel;
    
    reduceOrderBook();
};

void Commodity::handleReplace(Order *replace) {
    Order *toReplace = ordersBook[replace->id];
    toReplace->active = false;
    handleOrder(replace);
};

void Commodity::reduceOrderBook() {
    // Perform matching until there is no match
    while (true) {
        // From the invariant that the only possible trade is from the top of both queues
        if (buyQueue.empty() || sellQueue.empty()) {
            return;
        }
        
        // Highest priority orders
        Order *topBuy = buyQueue.top();
        Order *topSell = sellQueue.top();
        
        // Ensure neither order was cancelled
        if (!topBuy->active) {
            buyQueue.pop();
            delete topBuy;
            continue;
        } else if (!topSell->active) {
            sellQueue.pop();
            delete topSell;
            continue;
        }
        
        // Continue only if the prices match
        if (topBuy->price < topSell->price) {
            return;
        }
        
        // We have a match FILL the order by subtracting out min quantity
        int quantity = topBuy->quantity < topSell->quantity ? topBuy->quantity : topSell->quantity;
        topBuy->quantity -= quantity;
        topSell->quantity -= quantity;
        
        // Log the FILL
        std::cout << "FILL " << topBuy->symbol << " " << topBuy->id << " " << topSell->id << " " << quantity << " " << topSell->price << std::endl;
        
        // Remove completely filled orders
        if (topBuy->quantity == 0) {
            ordersBook.erase(topBuy->id);
            buyQueue.pop();
            delete topBuy;
        }
        if (topSell->quantity == 0) {
            ordersBook.erase(topSell->id);
            sellQueue.pop();
            delete topSell;
        }
    }
}

Commodity::~Commodity() {
    while (!buyQueue.empty()) {
        delete buyQueue.top();
        buyQueue.pop();
    }
    
    while (!sellQueue.empty()) {
        delete sellQueue.top();
        sellQueue.pop();
    }
}