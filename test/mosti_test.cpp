#include "gtest/gtest.h"
#include <Mosti/emulator.h>

TEST(MostiTest, Basic) {
    EXPECT_EQ(1, 1);
}

TEST(MostiTest, CPU) {
    emulator::CPU cpu;
    EXPECT_EQ(1, cpu.execute(std::span<const std::uint8_t>({1, 2, 3})));
}
