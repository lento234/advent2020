// Advent of Code: Day 3
// Lento Manickathan

#include <vector>
#include <string>
#include <fmt/ranges.h>
#include "util.h"

inline std::vector<std::vector<bool>> decode(const Message& input)
{
    std::vector<std::vector<bool>> decoded_input(input.n_rows);
    for (size_t i=0; i<input.n_rows; ++i)
        for (size_t j=0; j<input.n_cols; ++j)
            decoded_input[i].push_back((input.content[i][j] == '#') ? true : false);

    return decoded_input;
}

inline uint32_t count_trees(const std::vector<std::vector<bool>>& decoded_input, const uint32_t& row_shift, const uint32_t& col_shift)
{
    uint32_t n_trees = 0;
    for (size_t i=0, j=0; i<decoded_input.size(); i+=row_shift, j+=col_shift)
            if (decoded_input[i][j % decoded_input[i].size()])
                n_trees++;

    return n_trees;
}

static void answer1(const std::string& filename, const uint32_t& row_shift = 1, const uint32_t& col_shift = 3)
{
    // Read file
    Message test_input(filename);

    // Debugging
    //for (auto& line: test_input.content)
    //    fmt::print("{}\n", line);

    // decode message
    auto decoded_input = decode(test_input);
  
    // Count number of trees
    auto n_trees = count_trees(decoded_input, row_shift, col_shift); 

    fmt::print("Number of trees [right: {}, left: {}]: {}\n", row_shift, col_shift, n_trees);

}

int main()
{
    // Info
    const int day = 3;
    fmt::print("Advent of Code : Day {}\n", day);

    // Read file
    fmt::print("\nTest answer 1:\n");
    answer1("test_input.txt", 1, 3);
}
