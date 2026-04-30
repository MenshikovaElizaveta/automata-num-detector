cmake_minimum_required(VERSION 3.25)
project(DFA C)

include_directories(src)

add_executable(automata src/main.c src/dfa.c)
