#include "include/aes.hpp"
#include <iostream>
#include <random>
#include <cstring>

std::array<uint8_t, 16> generateRandomBlock() {
    std::array<uint8_t, 16> r{};
    std::random_device rd;
    std::uniform_int_distribution<int> dist(0, 255);
    for (auto& byte : r) {
        byte = static_cast<uint8_t>(dist(rd));
    }
    return r;
}

std::pair<std::array<uint8_t, 16>, std::array<uint8_t, 16>> PRB_encrypt(
    const AES128& aes, const std::array<uint8_t, 16>& plaintext)
{
    std::array<uint8_t, 16> R = generateRandomBlock();
    std::array<uint8_t, 16> FKR = aes.encryptBlock(R);

    std::array<uint8_t, 16> ciphertext;
    for (int i = 0; i < 16; ++i) {
        ciphertext[i] = FKR[i] ^ plaintext[i];
    }

    return {R, ciphertext};
}

std::array<uint8_t, 16> PRB_decrypt(
    const AES128& aes, const std::array<uint8_t, 16>& R, const std::array<uint8_t, 16>& ciphertext)
{
    std::array<uint8_t, 16> FKR = aes.encryptBlock(R);
    std::array<uint8_t, 16> plaintext;

    for (int i = 0; i < 16; ++i) {
        plaintext[i] = FKR[i] ^ ciphertext[i];
    }

    return plaintext;
}
