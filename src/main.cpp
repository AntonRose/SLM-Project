#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <stdexcept>
#include <map>
#include <cctype>

#include "read.h"
#include "model.h"



std::map<std::string, std::map<char, int> > build_counts(
    const std::vector<char>& chars, std::size_t k) {

    std::map<std::string, std::map<char, int> > counts;

    for (std::size_t i = 0; i + k < chars.size(); ++i) {
        std::string kgram;
        for (std::size_t j = i; j < i + k; ++j) {
            kgram.push_back(chars[j]);
        }
        char next = chars[i + k];
        
        counts[kgram][next]++;
    }
    return counts;
}

int main() {
    try {
        Reader reader("a_modest_proposal.txt");
        std::cout << reader.chars().size() << " characters loaded\n";
        const std::vector<char>& book = reader.chars();   // get at the stored text

        auto counts = build_counts(book, 3);
        
        for (const auto& [kgram, inner] : counts) {
        std::cout << '"' << kgram << "\": ";
        for (const auto& [next, n] : inner) {
            std::cout << next << ":" << n << "  ";
        }
        std::cout << '\n';
    }   
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << '\n';
        return 1;
    }


    std::string test = "abracadabra";
    std::vector<char> char_test(test.begin(), test.end());

    // std::map<std::string, std::map<char, int> > testcounts = build_counts(
    //     book, 1
    // );


    return 0;
}
