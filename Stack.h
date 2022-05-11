#pragma once
#include <iostream>
#include <vector>
#include <variant>
typedef std::variant<int, float> Variable; 

class Stack
{
private:
    std::vector<Variable> arr;

public:
    Stack();

    void push(Variable x);
    Variable pop();
    Variable top();
    
    int size();
    bool isEmpty();
    bool isFull();

    void print();
};