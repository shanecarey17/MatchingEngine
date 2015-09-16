cmake_minimum_required(VERSION 2.8.10)

PROJECT(hackathon)

add_subdirectory(MatchingEngine)

file(GLOB SOURCES "MatchingEngine/*.cpp")

add_executable(MatchingEngine ${SOURCES})
