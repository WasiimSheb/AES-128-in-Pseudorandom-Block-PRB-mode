#ifndef PRB_HPP
#define PRB_HPP

#include "aes.hpp"
#include <array>
#include <utility>

std::array<uint8_t, 16> generateRandomBlock();
std::pair<std::array<uint8_t, 16>, std::array<uint8_t, 16>> PRB_encrypt(const AES128& aes, const std::array<uint8_t, 16>& plaintext);
std::array<uint8_t, 16> PRB_decrypt(const AES128& aes, const std::array<uint8_t, 16>& R, const std::array<uint8_t, 16>& ciphertext);

#endif
