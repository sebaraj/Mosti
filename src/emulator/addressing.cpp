#include "addressing.h"

[[nodiscard]] inline std::uint16_t zeropage_indexed(emulator::CPU& cpu, const std::uint8_t value,
                                                    std::uint8_t emulator::Registers::* index) {
    return static_cast<uint16_t>(((cpu.reg).*index + value) & 0xff);
}

[[nodiscard]] inline std::uint16_t absolute_indexed(emulator::CPU& cpu, const std::uint8_t lsb,
                                                    const std::uint8_t hsb,
                                                    std::uint8_t emulator::Registers::* index) {
    const uint16_t address = (hsb << 8) | lsb;
    const uint16_t target_address = address + (cpu.reg).*index;
    return target_address & static_cast<std::uint16_t>(0xffff);
}

[[nodiscard]] inline std::uint16_t indirect(emulator::CPU& cpu, const std::uint16_t val) {
    const uint8_t lsb = cpu.get_memory(val);
    const uint16_t hsb_pos = static_cast<std::uint16_t>((val + 1) & 0xff);
    const uint8_t hsb = cpu.get_memory(hsb_pos);
    return static_cast<std::uint16_t>((hsb << 8) | lsb);
}

[[nodiscard]] inline std::uint16_t indexed_indirect(emulator::CPU& cpu, const std::uint8_t val) {
    const uint16_t indexed_address = static_cast<std::uint16_t>(val + cpu.reg.x);
    const uint16_t zp_addr = static_cast<std::uint16_t>(indexed_address & 0xff);
    return indirect(cpu, zp_addr);
}

[[nodiscard]] inline std::uint16_t indirect_indexed(emulator::CPU& cpu, const std::uint8_t val) {
    const uint16_t addr = indirect(cpu, val);
    return static_cast<std::uint16_t>(addr + cpu.reg.y);
}
