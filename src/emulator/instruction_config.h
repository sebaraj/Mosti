#ifndef INSTRUCTION_CONFIG_H
#define INSTRUCTION_CONFIG_H

#include <Mosti/emulator.h>

#include <cstdint>
#include <functional>
#include <optional>
#include <span>

/**
 * @brief InstructionConfig struct
 *
 * Contains the configuration for an instruction, bytes read, and cycles taken.
 */
struct InstructionConfig {
    size_t bytes;
    size_t cycles;

    /**
     * @brief Constructor for InstructionConfig
     *
     * @param bytes_read Number of bytes read
     * @param cycles Number of cycles taken
     */
    InstructionConfig(size_t bytes_read, size_t cycles) : bytes(bytes_read), cycles(cycles) {}

    /**
     * @brief Constructor for InstructionConfig with default (0) cycles
     *
     * @param bytes_read Number of bytes read
     */
    InstructionConfig(size_t bytes_read) : bytes(bytes_read), cycles(0) {}
};

using Instruction = std::function<std::optional<InstructionConfig>(emulator::CPU&,
                                                                   std::span<const std::uint8_t>)>;

#endif  // INSTRUCTION_CONFIG_H
