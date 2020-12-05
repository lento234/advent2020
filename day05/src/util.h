#pragma once

#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <fmt/ranges.h>

struct Text
{
    std::vector<std::string> raw;

    Text(const std::string& filename)
    {
        // Read file
        std::ifstream file(filename);
        if (!file.good())
            throw std::runtime_error("Failed to open!");

        // Buffer file
        std::string buffer;
        while (getline(file, buffer))
            raw.push_back(buffer);
        file.close();

    }

    size_t size() { return raw.size(); }

    void print()
    {
        fmt::print("    {}\n\n", fmt::join(raw, "\n    "));
    }

    std::string& operator[](const size_t i) { return raw[i]; }

    auto begin() const { return raw.begin(); }
    auto end() const { return raw.end(); }

};

