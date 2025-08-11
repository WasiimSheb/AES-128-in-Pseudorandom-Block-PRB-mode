# AES-128 in Pseudorandom Block (PRB) Mode

This assignment implements AES-128 from scratch in C++, and uses it in a textbook-defined encryption mode called **Pseudorandom Block (PRB)**. The PRB mode is based on encrypting a fresh random block `R` and XORing it with the plaintext to produce the ciphertext. Both `R` and the ciphertext are used for decryption.

The project is fully based on the following sources:
- FIPS PUB 197 – Advanced Encryption Standard (AES)
- NIST SP 800-90A – Random Number Generation using AES
- NIST SP 800-38A – Modes of operation (CTR reference)
- Herzberg’s *Introduction to Cryptography* – PRB mode concept
- *Cryptography Engineering* by Ferguson, Schneier, and Kohno

This implementation does **not** use any external cryptographic libraries and is designed for educational purposes.
