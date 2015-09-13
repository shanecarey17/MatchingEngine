//
//  Logger.cpp
//  MatchingEngine
//
//  Created by Shane Carey on 9/13/15.
//  Copyright © 2015 Shane Carey. All rights reserved.
//

#include "Logger.hpp"

#include <iostream>

void Logger::setOutFile(std::string file) {
    outFile = std::ofstream(file);
}

void Logger::writeToOutFile(std::string output) {
    outFile << output << std::endl;
}