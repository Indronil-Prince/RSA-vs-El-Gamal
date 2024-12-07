#include "RSA.h"
#include "ElGamal.h"
#include "FileIO.h"
#include <iostream>
#include <chrono>
#include <iomanip>

using namespace std;
using namespace NTL;

int main() {
    chrono::steady_clock::time_point start, end;
    chrono::duration<double> elapsed, total_rsa_time(0.0), total_elgamal_time(0.0);

    RSA rsa;
    ElGamal elgamal;

    string inputFilePath = "InputOutput/input.txt";
    string encryptedFilePath = "InputOutput/encrypted";
    string decryptedFilePath = "InputOutput/decrypted";

    ZZ message = FileIO::ReadZZFromFile(inputFilePath);
    long length = NumBits(message);
    cout << "The number of bits in the message is: " << length << endl;
    cout << "--------------------------------------------------------------" << endl;
    
    int keylength;
    cout << "Enter the keylength (in bits): ";
    cin >> keylength;
    cout << "--------------------------------------------------------------" << endl;

    // RSA Encryption
    ZZ n, e, d;
    rsa.GenerateKeys(n, e, d, keylength);

    start = chrono::steady_clock::now();
    ZZ rsaEncrypted = rsa.Encrypt(n, e, message);
    end = chrono::steady_clock::now();
    elapsed = chrono::duration_cast<chrono::duration<double>>(end - start);
    total_rsa_time += elapsed;
    cout << fixed << setprecision(4) << "RSA Encryption completed in " << elapsed.count() * 1000 << " milliseconds." << endl;
    FileIO::WriteZZToFile(encryptedFilePath + "_rsa.txt", rsaEncrypted);

    // RSA Decryption
    start = chrono::steady_clock::now();
    ZZ rsaDecrypted = rsa.Decrypt(n, d, rsaEncrypted);
    end = chrono::steady_clock::now();
    elapsed = chrono::duration_cast<chrono::duration<double>>(end - start);
    total_rsa_time += elapsed;
    cout << fixed << setprecision(4) << "RSA Decryption completed in " << elapsed.count() * 1000 << " milliseconds." << endl;
    cout << fixed << setprecision(4) << "RSA total completed in " << total_rsa_time.count() * 1000 << " milliseconds." << endl;
    cout << "--------------------------------------------------------------" << endl;
    FileIO::WriteZZToFile(decryptedFilePath + "_rsa.txt", rsaDecrypted);

    // ElGamal Encryption
    ZZ p1, g, h, x;
    elgamal.GenerateKeys(p1, g, h, x, keylength);

    start = chrono::steady_clock::now();
    auto elGamalEncrypted = elgamal.Encrypt(p1, g, h, message);
    end = chrono::steady_clock::now();
    elapsed = chrono::duration_cast<chrono::duration<double>>(end - start);
    total_elgamal_time += elapsed;
    cout << fixed << setprecision(4) << "ElGamal Encryption completed in " << elapsed.count() * 1000 << " milliseconds." << endl;
    FileIO::WriteZZToFile(encryptedFilePath + "_elgamal.txt", elGamalEncrypted.first);
    FileIO::WriteZZToFile(encryptedFilePath + "_elgamal.txt", elGamalEncrypted.second);

    // ElGamal Decryption
    start = chrono::steady_clock::now();
    ZZ elGamalDecrypted = elgamal.Decrypt(p1, x, elGamalEncrypted.first, elGamalEncrypted.second);
    end = chrono::steady_clock::now();
    elapsed = chrono::duration_cast<chrono::duration<double>>(end - start);
    total_elgamal_time += elapsed;
    cout << fixed << setprecision(4) << "ElGamal Decryption completed in " << elapsed.count() * 1000 << " milliseconds." << endl;
    cout << fixed << setprecision(4) << "ElGamal total completed in " << total_elgamal_time.count() * 1000 << " milliseconds." << endl;
    cout << "--------------------------------------------------------------" << endl;
    FileIO::WriteZZToFile(decryptedFilePath + "_elgamal.txt", elGamalDecrypted);

    return 0;
}
