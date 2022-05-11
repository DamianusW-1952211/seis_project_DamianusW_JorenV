#include <iostream>
#include <vector>
#include <string>
#include <cstddef>
#include <bitset>
#include <iomanip>
#include <stdexcept>
#include <fstream>
#include "ByteStream.cpp"
#include "Stack.cpp"

int main()
{
	Stack s = Stack();

	s.push(300);
	s.push(5);
	s.push(666);
	s.push(437);
	s.push(432);

	s.print();

    return 0;
}