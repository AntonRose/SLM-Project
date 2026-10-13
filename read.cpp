#include "read.h"
#include <cctype>
#include <fstream>
#include <stdexcept>

// std::vector<char> read_file(const std::string& file_path) {
//     std::ifstream in(file_path);
//     std::vector<char> chars;

//     if (!in.is_open()) {
//         throw std::runtime_error("Failed to open file: " + file_path);
//     }

//     char c;
//     while (in.get(c)) {
//             unsigned char u = static_cast<unsigned char>(c);
//             if (u > 127) continue;                 // skip non-ASCII bytes
//             if (c == '\n' || c == '\r') continue;  // skip newlines, as before
//             chars.push_back(static_cast<char>(std::tolower(u)));
//         }
//     return chars;
// }

Reader::Reader(const std::string& file_path) {
    std::ifstream in(file_path);
    if (!in.is_open()) {
        throw std::runtime_error("Failed to open file: " + file_path);
    }

    char c;
    while (in.get(c)) {
        unsigned char u = static_cast<unsigned char>(c);
        if (u > 127) continue;                  // skip non-ASCII bytes
        if (c == '\n' || c == '\r') continue;   // skip newlines
        chars_.push_back(static_cast<char>(std::tolower(u)));
    }
}

const std::vector<char>& Reader::chars() const {
    return chars_;
}
