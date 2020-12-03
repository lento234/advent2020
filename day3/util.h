#pragma once

#include <string>
#include <vector>
#include <fstream>

struct Message
{
    std::vector<std::string> content;
    size_t n_rows;
    size_t n_cols;

    //inline std::vector<std::string> read_file(const std::string& filename)
    Message(const std::string& filename)
    {
        // Read file
        std::ifstream file(filename);
        if (!file.good())
            throw std::runtime_error("Failed to open!");

        // Buffer file
        std::string buffer;
        while (file >> buffer)
            content.push_back(buffer);
        
        // Close the file.
        file.close();
       
        // Determine message size
        n_rows = content.size();
        n_cols = content[0].size();

    }

    inline size_t size() { return n_rows * n_cols; }

};

