#include <Mosti/emulator.h>

#include <cstdint>

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
std::size_t CPU::execute(std::span<const std::uint8_t> program) { return 1; }
}  // namespace emulator
