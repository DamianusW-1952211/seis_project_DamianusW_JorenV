#include <iostream>
#include <vector>
#include <string>
#include <cstddef>
#include <bitset>
#include <iomanip>
#include "Bytestream.h"

ByteStream::ByteStream(std::vector<uint8_t> b):currentByteIndex{0}
{
	size = b.size();
	buffers = b;
}

uint8_t ByteStream::readByte()
{
	uint8_t b = buffers[currentByteIndex];
	++currentByteIndex;
	return b;
}

//Test voor geschreven
std::string ByteStream::readASCIIString()
{
	std::string string{""};

	for(int i = 0; i < size; ++i) string += readByte();

	return string;
}

//test voor geschreven
//wikepedia voorbeeld (https://en.wikipedia.org/wiki/LEB128)
int32_t ByteStream::readInt32()
{
	uint8_t byte{0};
	int32_t result{0};
	int shift{0};

	do
	{
	  byte = readByte();
	  result |= ((byte & 0x7f) << shift);
	  shift += 7;
	} while ((byte & 0x80) != 0); //Kijkt of de meest linkse byte van het programma gelijk is aan nul

	/* sign bit of byte is second high-order bit (0x40) */
	if ((shift < 32) && (byte & 0x40) != 0) // indien er size wordt gebruikt in plaats van 32 dan werkt het niet
	{
		/* sign extend */
	  result |= (~0 << shift);
	}

	return result;
}

//test voor geschreven
//wikipedia voorbeerld (https://en.wikipedia.org/wiki/LEB128)
uint32_t ByteStream::readUInt32()
{
	uint8_t byte{0};
	uint32_t result = 0;
	int shift = 0;

	while (true)
	{
	  byte = readByte();
	  result |= ((byte & 0x7f)) << shift;
	  if ((byte & 0x80) == 0)
	  {
		  return result;
	  }
	  shift += 7;
	}
}

void ByteStream::seek(int offset)
{
	currentByteIndex += offset;
}

//functie nog te schrijven
float ByteStream::readFloat32()
{
	float result{0};

	for (int i = 0; i < 4; ++i) {
        *((uint8_t*)(&result) + i) = readByte();
    }

	return result;
}