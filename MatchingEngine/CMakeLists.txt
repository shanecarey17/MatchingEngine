cmake_minimum_required(VERSION 2.8.10)
PROJECT(MatchingEngine)

if (UNIX)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
endif()

file(GLOB MATCHINGENGINE_SRCS "*.cpp")
ADD_EXECUTABLE (MatchingEngine ${MATCHINGENGINE_SRCS})
