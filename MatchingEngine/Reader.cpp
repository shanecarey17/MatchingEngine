//
//  Reader.cpp
//  MatchingEngine
//
//  Created by Shane Carey on 9/13/15.
//  Copyright © 2015 Shane Carey. All rights reserved.
//

#include "Reader.hpp"

#include <sstream>
#include <vector>

Reader::Reader(std::string file) : infile(file) {}

Order *Reader::nextOrder() {
    std::string line;
    if (std::getline(infile, line)) {
        // Tokenize string
        std::istringstream iss(line);
        std::vector<std::string> tokens;
        std::string token;
        while (std::getline(iss, token, ',')) {
            tokens.push_back(token);
        }
        
        // Return order
        Order *order = new Order();
        order->type = tokens[0];
        order->id = std::stoi(tokens[1]);
        order->symbol = tokens[2];
        order->side = tokens[3];
        order->quantity = std::stoi(tokens[4]);
        order->price = std::stof(tokens[5]);
        
        return order;
    } else {
        return NULL;
    }
}