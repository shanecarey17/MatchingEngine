//
//  Order.cpp
//  MatchingEngine
//
//  Created by Shane Carey on 9/13/15.
//  Copyright © 2015 Shane Carey. All rights reserved.
//

#include "Order.hpp"

Order::Order() {
    active = true;
}

// Comparator
bool Order::operator()(Order *order1, Order *order2) {
    if (order1->side[0] == 'B') {
        // BUY return highest price
        if (order1->price == order2->price) {
            return order1->id > order2->id;
        } else {
            return order1->price < order2->price;
        }
    } else {
        // SELL return lowest price
        if (order1->price == order2->price) {
            return order1->id > order2->id;
        } else {
            return order1->price > order2->price;
        }
    }
}