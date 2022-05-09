#include <iostream>
#include <vector>
#include <string>
#include <cstddef>
#include <bitset>
#include <iomanip>
#include <stdexcept>
#include <fstream>
#include "ByteStream.cpp"

int main()
{
	std::vector<uint8_t> v = {0x48, 0x65, 0x6C, 0x6C, 0x6F};
	ByteStream bs = ByteStream(v);

	std::cout <<  bs.readASCIIString() << std::endl;

    return 0;
}