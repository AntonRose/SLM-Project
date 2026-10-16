#include "read.h"
#include <cctype>
#include <fstream>
#include <stdexcept>


Reader::Reader(const std::string& file_path) {
    std::ifstream in(file_path);
    if (!in.is_open()) {
        throw std::runtime_error("Failed to open file: " + file_path);
    }

    char c;
    while (in.get(c)) {
        unsigned char u = static_cast<unsigned char>(c);
        if (u > 127) continue;
        if (c == '\n' || c == '\r') continue; 
        chars_.push_back(static_cast<char>(std::tolower(u)));
    }
}

const std::vector<char>& Reader::chars() const {
    return chars_;
}
