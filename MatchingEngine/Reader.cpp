//
//  Reader.cpp
//  MatchingEngine
//
//  Created by Shane Carey on 9/13/15.
//  Copyright © 2015 Shane Carey. All rights reserved.
//

#include "Reader.hpp"

#include <iostream>
#include <sstream>
#include <vector>
#include <locale>

struct CommaDelim : std::ctype<char> {
    
    CommaDelim(): std::ctype<char>(table()) {}
    
    static std::ctype_base::mask const* table() {
        static std::vector<std::ctype_base::mask> repChar(table_size, std::ctype_base::mask());
        
        repChar[','] = std::ctype_base::space;
        repChar['\n'] = std::ctype_base::space;
        repChar[' '] = std::ctype_base::space;
        
        return &repChar[0];
    }
};

Order *Reader::nextOrder() {
    std::string line;
    if (std::getline(std::cin, line)) {
        // Parse line
        std::istringstream iss(line);
        static std::locale locale(std::locale(), new CommaDelim());
        iss.imbue(locale);
        
        // Return order
        Order *order = new Order();
        iss >> order->type;
        iss >> order->id;
        iss >> order->symbol;
        iss >> order->side;
        iss >> order->quantity;
        iss >> order->price;
        
        return order;
    } else {
        return NULL;
    }
}