#pragma once
#include <cstddef>
#include <map>
#include <set>
#include <string>
#include <vector>

class Model {
public:
    Model(std::size_t k, double alpha = 0.0);
    void train(const std::vector<char>& chars);

private:
    std::size_t k_;
    double alpha_;
    std::map<std::string, std::map<char, int> > counts_;
    std::set<char> alphabet_;
};
