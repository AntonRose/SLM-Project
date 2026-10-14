#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <stdexcept>
#include <map>
#include <cctype>

#include "read.h"
#include "model.h"





int main() {
    try {
        // std::string s = "chicken burger chips please boss";
        // std::vector<char> text(s.begin(), s.end());

        Reader reader("a_modest_proposal.txt");
        std::cout << reader.chars().size() << " characters loaded\n";
        const std::vector<char>& book = reader.chars();  

        
        Model model(5, 0.0);
        model.train(book);
        model.generate(200);
        std::cout << '\n';
    } 
    
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << '\n';
        return 1;
    }

    return 0;
}
