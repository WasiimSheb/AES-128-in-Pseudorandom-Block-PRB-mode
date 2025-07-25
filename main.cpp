#include "aes.hpp"
#include <iostream>
#include <iomanip>
#include <array>
#include "prb.cpp"  // include PRB logic

void printBlock(const std::array<uint8_t, 16>& block) {
    for (auto b : block) {
        std::cout << std::hex << std::setw(2) << std::setfill('0') << int(b) << " ";
    }
    std::cout << "\n";
}

int main() {
    std::array<uint8_t, 16> key = {0x2b, 0x7e, 0x15, 0x16, 0x28, 0xae, 0xd2, 0xa6,
                                   0xab, 0xf7, 0x4f, 0x34, 0x4d, 0xa5, 0x6f, 0x3c};
    AES128 aes(key);

    std::array<uint8_t, 16> plaintext = { 
        'H', 'e', 'l', 'l', 'o', ' ', 'P', 'R', 'B', ' ', 'M', 'o', 'd', 'e', '!', '!'
    };

    auto [R, ciphertext] = PRB_encrypt(aes, plaintext);
    auto recovered = PRB_decrypt(aes, R, ciphertext);

    std::cout << "Plaintext:  "; printBlock(plaintext);
    std::cout << "R:          "; printBlock(R);
    std::cout << "Ciphertext: "; printBlock(ciphertext);
    std::cout << "Recovered:  "; printBlock(recovered);

    return 0;
}
