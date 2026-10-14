#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <stdexcept>
#include <map>
#include <chrono>
#include <cctype>

#include "read.h"
#include "model.h"





int main(int argc, char* argv[]) {
    std::cerr << "main started, argc=" << argc << '\n';

    try {
        // std::string s = "chicken burger chips please boss";
        // std::vector<char> text(s.begin(), s.end());

        double alpha = 0.0;
        int i = 1;

        if (argc > 1 && std::string(argv[1]) == "-a") {
            if (argc < 3) {
                throw std::invalid_argument("-a needs a value");
            }
            std::size_t posA = 0;
            alpha = std::stod(argv[2], &posA);
            if (posA != std::string(argv[2]).size()) {
                throw std::invalid_argument("alpha must be a number");
            }
            i = 3;
        }

        if (argc - i != 3) {
            std::cerr << "Usage: " << argv[0] << " [-a alpha] k file length\n";
            return 1;
        }

        
        std::size_t pos = 0;
        int k = std::stoi(argv[i], &pos);
        if (pos != std::string(argv[i]).size()) {
        throw std::invalid_argument("k must be an integer");
        }

        std::string file = argv[i+1];

        std::size_t pos2 = 0;
        int length = std::stoi(argv[i + 2], &pos2);
        if (pos2 != std::string(argv[i + 2]).size()) {
        throw std::invalid_argument("length must be an integer");
        }

        std::cerr << "alpha=" << alpha << " k=" << k
          << " file=" << file << " length=" << length << '\n';

        // Reader reader(file);
        // std::cout << reader.chars().size() << " characters loaded\n";
        // const std::vector<char>& text = reader.chars();  

        
        // Model model(k, alpha);
        // model.train(text);
        // model.generate(length);
        
        auto t0 = std::chrono::steady_clock::now();
        Reader reader(file);
        auto t1 = std::chrono::steady_clock::now();
        Model model(k, alpha);
        model.train(reader.chars());
        auto t2 = std::chrono::steady_clock::now();
        model.generate(length);
        auto t3 = std::chrono::steady_clock::now();

        std::chrono::duration<double> read = t1 - t0, train = t2 - t1, gen = t3 - t2;
        std::cerr << "read " << read.count() << " s, train " << train.count()
          << " s, generate " << gen.count() << " s\n";

          std::cout << '\n';
        }


        catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << '\n';
        return 1;
        }

    return 0;
} 
    
    