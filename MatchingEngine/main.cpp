//
//  main.cpp
//  MatchingEngine
//
//  Created by Shane Carey on 9/12/15.
//  Copyright © 2015 Shane Carey. All rights reserved.
//

#include "Reader.hpp"
#include "Logger.hpp"
#include "Exchange.hpp"
#include "Order.hpp"

int main(int argc, char *argv[])
{
    Reader inReader(argv[1]);
    Logger::logger().setOutFile(argv[2]);
    
    Exchange exchange = Exchange();
    
    Order *nextOrder = inReader.nextOrder();
    while (nextOrder) {
        exchange.match(nextOrder);
        nextOrder = inReader.nextOrder();
    }
    
    return 0;
}

