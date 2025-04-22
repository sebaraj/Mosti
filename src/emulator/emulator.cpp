#include <Mosti/emulator.h>

#include "instruction_config.h"

namespace emulator {

bool operator==(Flags const& lhs, Flags const& rhs) {
    return lhs.n == rhs.n && lhs.v == rhs.v && lhs.b == rhs.b && lhs.d == rhs.d && lhs.i == rhs.i
           && lhs.z == rhs.z && lhs.c == rhs.c;
}

bool operator==(Registers const& lhs, Registers const& rhs) {
    return lhs.a == rhs.a && lhs.x == rhs.x && lhs.y == rhs.y && lhs.pc == rhs.pc
           && lhs.sp == rhs.sp;
}

// CPU method implementations
Flags CPU::get_flags() const { return flags; }

Registers CPU::get_registers() const { return reg; }

uint8_t CPU::get_memory(uint16_t address) const { return mem[address]; }

std::size_t CPU::execute(std::span<const std::uint8_t> program) {
    if (program.empty()) {
        return 0;
    }
    return 1;
}

std::uint8_t CPU::serialize_flags() const {
    return (static_cast<int>(flags.n) << 7 | static_cast<int>(flags.v) << 6
            | static_cast<int>(flags.b) << 4 | static_cast<int>(flags.d) << 3
            | static_cast<int>(flags.i) << 2 | static_cast<int>(flags.z) << 1
            | static_cast<int>(flags.c));
}

}  // namespace emulator
