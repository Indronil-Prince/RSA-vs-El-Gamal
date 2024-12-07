# Cryptography Performance Analysis

This project contains implementations of RSA and ElGamal cryptographic algorithms and compares their performance across different key sizes. It is designed to provide insights into the encryption and decryption times for varying message bit sizes using 512-bit, 1024-bit, and 2048-bit keys.

## Prerequisites

Before you run this project, ensure you have the following installed:
- [GCC](https://gcc.gnu.org/) or any preferred C++ compiler supporting C++17 or later
- [NTL (Number Theory Library)](http://www.shoup.net/ntl/)
- [GMP (GNU Multiple Precision Arithmetic Library)](https://gmplib.org/)

## Compile the Code

To compile the project, use the following command:

```bash
g++ -std=c++11 -o cryptoProject main.cpp RSA.cpp ElGamal.cpp FileIO.cpp -lntl -lgmp

Make sure all source files (main.cpp, RSA.cpp, RSA.h, ElGamal.cpp, ElGamal.h, FileIO.cpp, FileIO.h) are in the same directory and that the paths to the NTL and GMP libraries are correctly configured in your system's environment.


To run the program, simply execute the compiled binary:

```bash
./crypto

The program will prompt for inputs such as message bits and key size. Enter the appropriate values to see the performance metrics for RSA and ElGamal algorithms.

**Input**
The program will read the message bits from InputOutput/input.txt and output the encrypted and decrypted texts into their respective files in the InputOutput folder.

**Output**
RSA and ElGamal encrypted and decrypted outputs are written to separate files:
rsa_encrypted.txt
rsa_decrypted.txt
elgamal_encrypted.txt
elgamal_decrypted.txt

# Cryptography Performance Analysis

This project contains implementations of RSA and ElGamal cryptographic algorithms and compares their performance across different key sizes. It is designed to provide insights into the encryption and decryption times for varying message bit sizes using 512-bit, 1024-bit, and 2048-bit keys.

## Prerequisites

Before you run this project, ensure you have the following installed:
- [GCC](https://gcc.gnu.org/) or any preferred C++ compiler supporting C++17 or later
- [NTL (Number Theory Library)](http://www.shoup.net/ntl/)
- [GMP (GNU Multiple Precision Arithmetic Library)](https://gmplib.org/)

## Compile the Code

To compile the project, use the following command:

```bash
g++ -std=c++11 -o cryptoProject main.cpp RSA.cpp ElGamal.cpp FileIO.cpp -lntl -lgmp

Make sure all source files (main.cpp, RSA.cpp, RSA.h, ElGamal.cpp, ElGamal.h, FileIO.cpp, FileIO.h) are in the same directory and that the paths to the NTL and GMP libraries are correctly configured in your system's environment.


To run the program, simply execute the compiled binary:

```bash
./cryptoProject

The program will prompt for inputs such as key size. Enter the appropriate values to see the performance metrics for RSA and ElGamal algorithms.


**Input files**
The program will read the message bits from InputOutput/input.txt and output the encrypted and decrypted texts into their respective files in the InputOutput folder.

**Output files**
RSA and ElGamal encrypted and decrypted outputs are written to separate files:
rsa_encrypted.txt
rsa_decrypted.txt
elgamal_encrypted.txt
elgamal_decrypted.txt


**Sample Output**

The number of bits in the message is: 1022
--------------------------------------------------------------
Enter the keylength (in bits): 2048
--------------------------------------------------------------
RSA Encryption completed in 0.0758 milliseconds.
RSA Decryption completed in 15.3004 milliseconds.
RSA total completed in 15.3762 milliseconds.
--------------------------------------------------------------
ElGamal Encryption completed in 4.3472 milliseconds.
ElGamal Decryption completed in 2.8234 milliseconds.
ElGamal total completed in 7.1706 milliseconds.
--------------------------------------------------------------