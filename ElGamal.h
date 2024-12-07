#ifndef ELGAMAL_H
#define ELGAMAL_H

#include <NTL/ZZ.h>

using namespace NTL;

class ElGamal {
public:
    void GenerateKeys(ZZ& p, ZZ& g, ZZ& h, ZZ& x, int& keylength);
    std::pair<ZZ, ZZ> Encrypt(const ZZ& p, const ZZ& g, const ZZ& h, const ZZ& message);
    ZZ Decrypt(const ZZ& p, const ZZ& x, const ZZ& c1, const ZZ& c2);
};

#endif // ELGAMAL_H
