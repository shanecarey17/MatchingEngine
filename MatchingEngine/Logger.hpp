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
    static Logger &logger() {
        static Logger logger;
        return logger;
    };
    
    void setOutFile(std::string file);
    
    void writeToOutFile(std::string output);
    
private:
    std::ofstream outFile;
    
    Logger() {};
    Logger(Logger const&) = delete;
    Logger& operator=(Logger const&) = delete;
    
};

#endif /* Logger_cpp */
