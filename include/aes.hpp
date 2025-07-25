#ifndef AES_HPP
#define AES_HPP

#include <array>
#include <cstdint>
#include <vector>

class AES128 {
public:
    AES128(const std::array<uint8_t, 16>& key);
    std::array<uint8_t, 16> encryptBlock(const std::array<uint8_t, 16>& input);

private:
    void keyExpansion();
    void addRoundKey(std::array<uint8_t, 16>& state, int round);
    void subBytes(std::array<uint8_t, 16>& state);
    void shiftRows(std::array<uint8_t, 16>& state);
    void mixColumns(std::array<uint8_t, 16>& state);

    std::array<uint8_t, 16> roundKeys[11];  // 11 round keys for AES-128
    std::array<uint8_t, 16> key;
};

#endif
