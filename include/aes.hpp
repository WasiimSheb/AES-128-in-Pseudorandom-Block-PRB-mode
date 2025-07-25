#ifndef AES_HPP
#define AES_HPP

#include <array>
#include <cstdint>
#include <vector>

class AES128 {
public:
    AES128(const std::array<uint8_t, 16>& key);

    std::array<uint8_t, 16> encryptBlock(const std::array<uint8_t, 16>& input) const;

private:
    void keyExpansion();  // modifies internal state, NOT const

    void addRoundKey(std::array<uint8_t, 16>& state, int round) const;
    void subBytes(std::array<uint8_t, 16>& state) const;
    void shiftRows(std::array<uint8_t, 16>& state) const;
    void mixColumns(std::array<uint8_t, 16>& state) const;

    std::array<uint8_t, 16> roundKeys[11];
    std::array<uint8_t, 16> key;
};

#endif
