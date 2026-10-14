#include "model.h"
#include <random>
#include <iostream>
#include <iomanip>

// Choose a starting g gram w based on their frequencies
// Output w
// Look up the next character distribution 

Model::Model(std::size_t k, double alpha)
 : k_(k), alpha_(alpha), rng_(12345) {
    if (alpha < 0.0) {
        throw std::runtime_error("Enter alpha >= 0");
    } 
}

void Model::train(const std::vector<char>& chars) {
    counts_.clear();
    alphabet_.clear();

    // std::map<std::string, std::map<char, int> > build_counts(
    // const std::vector<char>& chars, std::size_t k) {

    //     std::map<std::string, std::map<char, int> > counts;

    for (std::size_t i = 0; i + k_ < chars.size(); ++i) {
        std::string kgram;
        for (std::size_t j = i; j < i + k_; ++j) {
            kgram.push_back(chars[j]);
        }
        char next = chars[i + k_];
        
        counts_[kgram][next]++;

        for (char c : chars) {
            alphabet_.insert(c);
        }
}

char Model::sample_next(const std::string& kgram) {
    auto it = counts_.find(kgram);

    std::vector<char> letters;
    std::vector<double> weights;
    double total = 0.0;

    for (char c : alphabet_) {
        double n = 0.0;
        if (it != counts_.end()) {
            auto jt = it->second.find(c);
            if (jt != it->second.end()) {
                n = jt->second;
            }
        }
        double weight = n + alpha_;
        letters.push_back(c);
        weights.push_back(weight);
        total += weight;
    }


    if (total <= 0.0) {
        throw std::runtime_error("No possible next character for: " + kgram);
    }

    std::discrete_distribution<std::size_t> dist(weights.begin(), weights.end());
    return letters[dist(rng_)];
}

std::string Model::random_kgram() {
    if (counts_.empty()) {
        throw std::runtime_error("No training text");
    }

    std::vector<std::string> kgrams;
    std::vector<double> weights;

    for (const auto& [kgram, inner] : counts_) {
        double n_w = 0.0;                    // n(w)
        for (const auto& [c, n] : inner) {
            n_w += n;
        }
        kgrams.push_back(kgram);
        weights.push_back(n_w);
    }

    std::discrete_distribution<std::size_t> dist(weights.begin(), weights.end());
    return kgrams[dist(rng_)];
}

std::string Model::generate(std::size_t length) {
    
}
