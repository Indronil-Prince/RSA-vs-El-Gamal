// FileIO.h

#ifndef FILEIO_H
#define FILEIO_H

#include <string>
#include <NTL/ZZ.h>

using namespace NTL;

class FileIO {
public:
    static ZZ ReadZZFromFile(const std::string& filename);
    static void WriteZZToFile(const std::string& filename, const ZZ& data);
};

#endif // FILEIO_H
