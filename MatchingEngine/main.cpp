//
//  main.cpp
//  MatchingEngine
//
//  Created by Shane Carey on 9/12/15.
//  Copyright © 2015 Shane Carey. All rights reserved.
//

#define OUT_FILE "/Users/Shane Carey/desktop/MatchingEngine/MatchingEngine/data/fills.txt"
#define IN_FILE "/Users/Shane Carey/desktop/MatchingEngine/MatchingEngine/data/small_orders.txt"

#include "Reader.hpp"
#include "Logger.hpp"
#include "Exchange.hpp"
#include "Order.hpp"

int main(int argc, char *argv[])
{
    Reader inReader(IN_FILE);
    Logger::logger(OUT_FILE);
    
    Exchange exchange = Exchange();
    
    Order *nextOrder = inReader.nextOrder();
    while (nextOrder) {
        exchange.match(nextOrder);
        nextOrder = inReader.nextOrder();
    }
    
    Logger::deallocate();
    
    return 0;
}

