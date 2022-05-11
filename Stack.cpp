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

Variable Stack::top()
{
    if(isEmpty()) exit(EXIT_FAILURE);

    std::visit([](const auto &x) { std::cout << "the top is: " << x << std::endl;}, arr.back());

    return arr.back();
}

//(https://stackoverflow.com/questions/62355613/stdvariant-cout-in-c)
void Stack::print()
{
    int size = arr.size() - 1;
    for(int i = 0; i <= size; ++i)
    {
        std::visit([](const auto &x) { std::cout << x << std::endl;}, arr[size - i]);
    }

    std::cout <<  std::endl;
}