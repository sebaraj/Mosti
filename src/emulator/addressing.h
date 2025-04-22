#include <Mosti/emulator.h>

/*
    Addressing helpers - zeropage + reg, indexed indirect, indirect indexed helpers
*/

/**
 * @brief aids in getting the indexed zeropage address
 * from the given argument to the opcode
 *
 * @param cpu: cpu object to operate on
 *
 * @param value: zeropage address to add the index to
 *
 * @param index: register to use as the index add value
 *
 * @return resolved target address
 */
inline std::uint16_t zeropage_indexed(emulator::CPU& cpu, const std::uint8_t value,
                                      std::uint8_t emulator::Registers::* index);

/**
 * @brief aids in getting the absolute indexed
 * address for absolute indexed addressing opcodes
 *
 * @param cpu: the object to operate on
 *
 * @param lsb: first byte after opcodes
 *
 * @param hsb: second byte after opcodes
 *
 * @param index: pointer to the register to use as the index add
 *
 * @return resolved target address
 */
inline std::uint16_t absolute_indexed(emulator::CPU& cpu, const std::uint8_t lsb,
                                      const std::uint8_t hsb,
                                      std::uint8_t emulator::Registers::* index);

/**
 * @brief aids with the fetching of an indirect address
 *
 * @param cpu: object to operate on
 *
 * @param val: 16-bit address that contains the memory to fetch
 *
 * @return 16-bit address result of the indirect fetch
 */
inline std::uint16_t indirect(emulator::CPU& cpu, const std::uint16_t val);

/**
 * @brief aids with the fetching of a indexed indirect opcode mode
 *
 * @param cpu: object to operate on
 *
 * @param val: zeropage memory to apply the index to
 *
 * @return target address
 */
inline std::uint16_t indexed_indirect(emulator::CPU& cpu, const std::uint8_t val);

/**
 * @brief aids with the fetching of an indirect indexed opcode mode
 *
 * @param cpu: object to operate on
 *
 * @param val: zeropage memory to fetch the indirect address
 *
 * @return target address
 */
inline std::uint16_t indirect_indexed(emulator::CPU& cpu, const std::uint8_t val);
