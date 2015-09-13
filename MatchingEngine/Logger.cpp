//
//  Logger.cpp
//  MatchingEngine
//
//  Created by Shane Carey on 9/13/15.
//  Copyright © 2015 Shane Carey. All rights reserved.
//

#include "Logger.hpp"

#include <iostream>

Logger *Logger::instance = NULL;

Logger *Logger::logger(std::string filename) {
    if(instance == NULL){
        instance = new Logger(filename);
    }
    return instance;
}

void Logger::log(std::string output) {
    outStream << output << std::endl;
}

Logger::~Logger() {
    delete instance;
}