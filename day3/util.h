#pragma once

#include <string>
#include <vector>
#include <fstream>


inline std::vector<std::string> read_file(const std::string& filename)
{
    // Read file
    std::ifstream file(filename);
    if (!file.good())
        throw std::runtime_error("Failed to open!");

    // Buffer file
    std::string buffer;
    std::vector<std::string> file_content;
    while (file >> buffer)
        file_content.push_back(buffer);
    
    // Close the file.
    file.close();

    return file_content;
}



