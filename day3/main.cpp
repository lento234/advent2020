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

inline uint32_t count_trees(const std::vector<std::vector<bool>>& decoded_input, const uint32_t& right, const uint32_t& down)
{
    uint32_t n_trees = 0;
    for (size_t i=0, j=0; i<decoded_input.size(); i+=down, j+=right)
            if (decoded_input[i][j % decoded_input[i].size()])
                n_trees++;

    return n_trees;
}

static void answer1(const std::string& filename, const uint32_t& right = 3, const uint32_t& down = 1)
{
    // Read file
    Message test_input(filename);

    // decode message
    auto decoded_input = decode(test_input);
  
    // Count number of trees
    auto n_trees = count_trees(decoded_input, right, down);

    fmt::print("Number of trees [right: {}, down: {}]: {}\n", right, down, n_trees);

}

static void answer2(const std::string& filename, const std::vector<std::vector<uint32_t>>& shift_list)
{
    // Read file
    Message test_input(filename);

    // decode message
    auto decoded_input = decode(test_input);
  
    // Count number of trees
    uint64_t product = 1;
    for (const auto& shift: shift_list)
    {   
        const uint32_t right = shift[0], down = shift[1];
        auto n_trees = count_trees(decoded_input, right, down);
        product *= n_trees;
    }
    fmt::print("Product number of trees: {}\n", product);

}

int main()
{
    // Info
    constexpr int day = 3;
    fmt::print("Advent of Code : Day {}\n", day);

    constexpr uint32_t right = 3, down = 1;
    
    // Test answer 1
    fmt::print("\nTest answer 1:\n");
    answer1("test_input.txt", right, down);
    
    // Answer 1
    fmt::print("\nAnswer 1:\n");
    answer1("input.txt", right, down);

    std::vector<std::vector<uint32_t>> shift_list = 
    {
        {1, 1},
        {3, 1},
        {5, 1},
        {7, 1},
        {1, 2}
    };
    
    // Test answer 2
    fmt::print("\nTest answer 2:\n");
    answer2("test_input.txt", shift_list);
    
    fmt::print("\nAnswer 2:\n");
    answer2("input.txt", shift_list);

}
