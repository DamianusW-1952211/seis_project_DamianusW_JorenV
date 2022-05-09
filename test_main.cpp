#include <vector>
#include <iostream>
#include <string>
#include "gtest/gtest.h"
#include "ByteStream.cpp"

TEST(readTest, unsignedNumbers) {
    std::vector<uint8_t> b = {0xE5, 0x8E, 0x26};
    ByteStream bs = ByteStream(b);
    uint32_t unsignedNumber{bs.readUInt32()};

    EXPECT_EQ(unsignedNumber, 624485);
}

TEST(readTest, signedNumbers) {
    std::vector<uint8_t> b = {0xC0, 0xBB, 0x78};
    ByteStream bs = ByteStream(b);
    int32_t signedNumber{bs.readInt32()};

    EXPECT_EQ(signedNumber, -123456);
}

TEST(readTest, string) {
    std::vector<uint8_t> v = {0x48, 0x65, 0x6C, 0x6C, 0x6F};
	ByteStream bs = ByteStream(v);

	std::string string{bs.readASCIIString()};

    EXPECT_EQ(string, "Hello");
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}