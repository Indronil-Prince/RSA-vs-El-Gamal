#include "RSA.h"
#include <NTL/ZZ.h>

using namespace std;
using namespace NTL;

void RSA::GenerateKeys(ZZ& n, ZZ& e, ZZ& d, int& keylength) {
    ZZ p = GenPrime_ZZ(keylength); // Generate a 512-bit prime
    ZZ q = GenPrime_ZZ(keylength);
    // cout << "p = " << p << endl;
    // cout << "q = " << q << endl;
    n = p * q;            // n = p * q
    ZZ phi = (p - 1) * (q - 1); // phi(n) = (p-1)*(q-1)

    e = ZZ(65537);        // Commonly used public exponent
    InvMod(d, e, phi);    // Compute d, the modular inverse of e mod phi
}

ZZ RSA::Encrypt(const ZZ& n, const ZZ& e, const ZZ& message) {
    return PowerMod(message, e, n);
}

ZZ RSA::Decrypt(const ZZ& n, const ZZ& d, const ZZ& cipher) {
    return PowerMod(cipher, d, n);
}