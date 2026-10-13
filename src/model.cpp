#include "model.h"

// Choose a starting g gram w based on their frequencies
// Output w
// Look up the next character distribution 

Model::Model(std::size_t k, double alpha) : k_(k), alpha_(alpha) {
}

void Model::train(const std::vector<char>& chars) {


    // std::map<std::string, std::map<char, int> > build_counts(
    // const std::vector<char>& chars, std::size_t k) {

    //     std::map<std::string, std::map<char, int> > counts;

    //     for (std::size_t i = 0; i + k < chars.size(); ++i) {
    //         std::string kgram;
    //         for (std::size_t j = i; j < i + k; ++j) {
    //             kgram.push_back(chars[j]);
    //         }
    //         char next = chars[i + k];
            
    //         counts[kgram][next]++;
    //     }
    //     return counts;
    }

    std::vector<char> generate(const std::map<std::string, std::map<char, int>>& counts) {

        std::vector<char> text;

        for (std::)

    }
}
