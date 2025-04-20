#ifndef EMULATOR_H
#define EMULATOR_H

#include <stdbool.h>
#include <stdint.h>

#include <array>
#include <span>

#ifndef CLOCK_SPEED_MHZ
#define CLOCK_SPEED_MHZ 1.023  // Apple II
#endif                         // CLOCK_SPEED_MHZ

namespace emulator {
struct Flags {
    bool n;
    bool v;
    bool b;
    bool d;
    bool i;
    bool z;
    bool c;
};

struct Registers {
    uint8_t a;         // Accumulator
    uint8_t x;         // X Register
    uint8_t y;         // Y Register
    uint16_t pc;       // Program Counter
    uint8_t sp{0xff};  // Stack Pointer
};

bool operator==(Flags const& lhs, Flags const& rhs);
bool operator==(Registers const& lhs, Registers const& rhs);

class CPU {
private:
    Registers reg{};
    Flags flags{};
    // memory, with 0x0000-0xFFFF range for main mem, vram
    std::array<uint8_t, 0x10000> mem{};
    double clock_speed = CLOCK_SPEED_MHZ;

public:
    Flags get_flags() const;
    Registers get_registers() const;
    uint8_t get_memory(uint16_t address) const;
    std::size_t execute(std::span<const std::uint8_t> program);
};

}  // namespace emulator

#endif  // EMULATOR_H
