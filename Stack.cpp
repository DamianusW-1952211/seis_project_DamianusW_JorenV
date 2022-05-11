#include "Stack.h"
#include <iostream>
#include <vector>
#include <variant>

Stack::Stack(){}

bool Stack::isEmpty()
{
    return arr.empty();
}

//denk niet dat dit nodig zal gaan zijn
bool Stack::isFull()
{
    if(arr.max_size() == arr.size()) return true;
    return false;
}

void Stack::push(Variable x)
{
    if(isFull()) exit(EXIT_FAILURE);

    arr.push_back(x);
}

Variable Stack::pop()
{
    if(isEmpty()) exit(EXIT_FAILURE);

    Variable x = arr.back();
    arr.pop_back();

    return x;
}

void Stack::print()
{
    for(int i = 0; i < arr.size(); ++i)
    {
        std::visit([](const auto &x) { std::cout << x << '\n';}, arr[i]);
    }

    std::cout <<  std::endl;
}