/* 
Purpose of this folder is to implement the following data structures:
Linked Lists                Breadth-First Search        Bit Manipulation
Trees, Tries, & Graphs      Depth-First Search          Memory (Stack vs. Heap)
Stacks & Queues             Binary Search               Recursion
Heaps                       Merge Sort                  Dynamic Programming
Vectors/Arraylists          Quick Sort                  Big O Time & Space
Hash Tables
*/

/*
Purpose of this file is to provide sets of data with which to 
test implementations of data structures and algorithms
*/

#ifndef DATA_H
#define DATA_H

#include <cmath>
#include <string>

class Data{
public:
    Data(); // Instantiates a data object responsible for producing data
    std::string getString();
    std::string getArrayOfStrings();

};

#endif