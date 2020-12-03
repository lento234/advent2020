#pragma once

#include <string>
#include <vector>
#include <fstream>

struct Message
{
    std::vector<std::string> content;
    size_t n_rows;
    size_t n_cols;
    bool decoded_message[n_cols];

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
       
        // Determine message
        file.close();
        n_rows = content.size();
        n_cols = content[0].size();

        // Decode message
        decode();

    }

    inline size_t size() { return n_rows * n_cols; }
    
    void decode()
    {
        //for (size_t i=0; i<n_rows; ++i)
            for (size_t j=0; j<n_cols; ++j)
                decoded_message[j] = (content[0][j] == 'x') ? true : false;
    } 


};

