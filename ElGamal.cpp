#include "ElGamal.h"
#include <NTL/ZZ.h>

using namespace NTL;

void ElGamal::GenerateKeys(ZZ& p, ZZ& g, ZZ& h, ZZ& x, int& keylength) {
    p = GenPrime_ZZ(keylength);
    g = conv<ZZ>(2);
    x = RandomBnd(p - 2) + 2;
    h = PowerMod(g, x, p);
}

std::pair<ZZ, ZZ> ElGamal::Encrypt(const ZZ& p, const ZZ& g, const ZZ& h, const ZZ& message) {
    ZZ y = RandomBnd(p - 2) + 2;
    ZZ c1 = PowerMod(g, y, p);
    ZZ s = PowerMod(h, y, p);
    ZZ c2 = (message * s) % p;
    return {c1, c2};
}

ZZ ElGamal::Decrypt(const ZZ& p, const ZZ& x, const ZZ& c1, const ZZ& c2) {
    ZZ s = PowerMod(c1, x, p);
    ZZ s_inv;
    InvMod(s_inv, s, p);
    return (c2 * s_inv) % p;
}
