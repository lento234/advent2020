// Advent of Code: Day 2
// Lento Manickathan

#include <fstream>
#include <vector>
#include <string>
#include <fmt/ranges.h>

inline std::vector<std::string> read_file(const char* filename)
{
    std::vector<std::string> vec;
    std::ifstream file(filename); // Input file stream object

    // Check if exists and then open the file.
    if (file.good())
    {
        // Push items into a vector
        std::string value;
        while (file >> value)
            vec.push_back(value);
    }
    // Close the file.
    file.close();

    return vec;
}


int main()
{
    // Info
    const unsigned int day = 2;
    fmt::print("Advent of Code : Day {}\n", day);
   
    std::vector<std::string> input = read_file("test_input.txt");

    fmt::print("{}\n", input);
}
