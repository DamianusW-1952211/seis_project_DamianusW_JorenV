#pragma once
#include <iostream>
#include <vector>
#include <iomanip>

class ByteStream
{
    private:
        std::vector<uint8_t> buffers;
        int currentByteIndex;
        int size;

    public:
        ByteStream(std::vector<uint8_t> b);
        uint8_t readByte();
        std::string readASCIIString();

        int32_t  readInt32();   //LEB128 decodeder
        uint32_t readUInt32(); //LEB128 decodeder

        // later add readInt64, readFloat64, etc.

        void seek(int offset); // move the currentByteIndex by offset (can be negative!)

        float readFloat32();

        // optional:
        // currentByteIndex();
        // remainingByteCount();
        // totalByteCount();
        // etc.

        // recommended (not necessarily on this class though):
        // printHex(char byte)
        // printBinary(char byte)
        // printBinary(int32_t val)
        // printBinary(uint32_t val)
};
