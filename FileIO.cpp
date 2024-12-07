// FileIO.cpp

#include "FileIO.h"
#include <fstream>
#include <sstream>

ZZ FileIO::ReadZZFromFile(const std::string& filename) {
    std::ifstream file(filename);
    std::string str;
    if (file.is_open()) {
        getline(file, str);
        file.close();
    }
    return conv<ZZ>(str.c_str());
}

void FileIO::WriteZZToFile(const std::string& filename, const ZZ& data) {
    std::ofstream file(filename);
    if (file.is_open()) {
        file << data;
        file.close();
    }
}
