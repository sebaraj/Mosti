/**
 * @file
 * @author Bryan SebaRaj <bryanwsebaraj@gmail.com>
 * @version 1.0
 * @section DESCRIPTION
 * This file contains the definition of the CPU class and its methods.
 */

#ifndef EMULATOR_H
#define EMULATOR_H

#include <array>
#include <cstddef>
#include <cstdint>
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
    Flags() : n(false), v(false), b(false), d(false), i(false), z(false), c(false) {};
};

struct Registers {
    uint8_t a;         // Accumulator
    uint8_t x;         // X Register
    uint8_t y;         // Y Register
    uint16_t pc;       // Program Counter
    uint8_t sp{0xff};  // Stack Pointer
    Registers() : a(0), x(0), y(0), pc(0), sp(0xff) {};
};

bool operator==(Flags const& lhs, Flags const& rhs);
bool operator==(Registers const& lhs, Registers const& rhs);

/**
 * @brief CPU class
 *
 * Provides an interface to the CPU of the emulator.
 *
 * Contains the registers, flags, and memory of the CPU.
 *
 * Provides methods to execute a program and get the state of the CPU.
 */
class CPU {
private:
    Registers reg{};
    Flags flags{};
    std::array<uint8_t, 0x10000> mem{};
    double clock_speed = CLOCK_SPEED_MHZ;

public:
    /**
     * @return CPU's flags: n, v, b, d, i, z, and c.
     */
    Flags get_flags() const;

    /**
     * @return CPU's registers: a, x, y, pc, and sp.
     */
    Registers get_registers() const;

    /**
     * @param address The address to access in memory.
     * @return CPU's memory, a 16-bit address space. 0x0000-0xFFFF. main mem and vram.
     */
    uint8_t get_memory(uint16_t address) const;

    /**
     * Execute a program
     * @param program A span of bytes representing the program to be executed.
     * @return The number of cycles taken to execute the program.
     */
    std::size_t execute(std::span<const std::uint8_t> program);

    CPU() : reg{}, flags{}, mem{} {};
};

}  // namespace emulator

#endif  // EMULATOR_H
