//
//  main.cpp
//  MatchingEngine
//
//  Created by Shane Carey on 9/12/15.
//  Copyright © 2015 Shane Carey. All rights reserved.
//

#include <fstream>
#include <iostream>

#include "Reader.hpp"
#include "Exchange.hpp"
#include "Order.hpp"

int main(int argc, char *argv[]) {
    
    std::ifstream in(argv[1]);
    auto cinBuf = std::cin.rdbuf();
    std::cin.rdbuf(in.rdbuf());
    
    std::ofstream out(argv[2]);
    auto coutBuf = std::cout.rdbuf();
    std::cout.rdbuf(out.rdbuf());
    
    Reader reader;
    Exchange exchange;
    
    Order *nextOrder;
    while ((nextOrder = reader.nextOrder()) != NULL) {
        exchange.match(nextOrder);
    }
    
    std::cin.rdbuf(cinBuf);
    std::cout.rdbuf(coutBuf);
    
    return 0;
}

