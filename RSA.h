#ifndef RSA_H
#define RSA_H

#include <NTL/ZZ.h>

using namespace NTL;

class RSA {
public:
    void GenerateKeys(ZZ& n, ZZ& e, ZZ& d, int& keylength);
    ZZ Encrypt(const ZZ& n, const ZZ& e, const ZZ& message);
    ZZ Decrypt(const ZZ& n, const ZZ& d, const ZZ& cipher);
};

#endif // RSA_H
