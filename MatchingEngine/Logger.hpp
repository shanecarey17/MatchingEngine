//
//  Logger.hpp
//  MatchingEngine
//
//  Created by Shane Carey on 9/13/15.
//  Copyright © 2015 Shane Carey. All rights reserved.
//

#ifndef Logger_cpp
#define Logger_cpp

#include <string>
#include <fstream>

class Logger {
public:
    static Logger *logger(std::string filename);
    void log(std::string output);
    ~Logger();
    
private:
    static Logger *instance;
    std::ofstream outStream;
    Logger(std::string filename) : outStream(filename) {};
};

#endif /* Logger_cpp */
