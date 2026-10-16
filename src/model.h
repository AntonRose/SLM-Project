#pragma once
#include <cstddef>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <random>
#include <iostream>

class Model {
public:
    Model(std::size_t k, double alpha = 0.0);
    void train(const std::vector<char>& chars);
    std::string generate(int length, std::ostream& out = std::cout);

private:
    char sample_next(const std::string& kgram);

    std::size_t k_;
    double alpha_;
    std::map<std::string, std::map<char, int> > counts_;
    std::set<char> alphabet_;
    std::mt19937 rng_;
    std::string random_kgram();
};
