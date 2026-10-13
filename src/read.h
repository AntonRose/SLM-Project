#pragma once
#include <string>
#include <vector>

class Reader {
    public:
        explicit Reader(const std::string& file_path);
        const std::vector<char>& chars() const;

    private:
        std::vector<char> chars_;
};
