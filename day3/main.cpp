// Advent of Code: Day 3
// Lento Manickathan

#include <vector>
#include <string>
#include <fmt/ranges.h>
#include "util.h"

inline uint32_t count_trees(const Message& input, const uint32_t& right, const uint32_t& down)
{
    const std::vector<std::string>& content = input.content; 

    uint32_t n_trees = 0;
    for (size_t i=0, j=0; i<input.n_rows; i+=down, j+=right)
        if (content[i][j % input.n_cols] == '#')
            n_trees++;

    return n_trees;
}

static void answer1(const Message& input, const uint32_t& right = 3, const uint32_t& down = 1)
{
    auto n_trees = count_trees(input, right, down);
    
    fmt::print("Number of trees [right: {}, down: {}]: {}\n", right, down, n_trees);

}

static void answer2(const Message& input, const std::vector<std::vector<uint32_t>>& shift_list)
{
    uint64_t product = 1;
    for (const auto& shift: shift_list)
    {   
        const uint32_t right = shift[0], down = shift[1];
        auto n_trees = count_trees(input, right, down);
        product *= n_trees;
    }
    fmt::print("Product number of trees: {}\n", product);

}

int main()
{
    // Header info
    constexpr int day = 3;
    fmt::print("//////////////////////////////\n");
    fmt::print("    Advent of Code : Day {}   \n", day);
    fmt::print("//////////////////////////////\n\n");

    // Read test file
    Message test_input("test_input.txt");

    // Map traversing direction
    constexpr uint32_t right = 3, down = 1;
    
    // Test answer 1
    fmt::print(">> Test answer 1:\n");
    answer1(test_input, right, down);
    
    // Read input file
    Message input("input.txt");
    
    // Answer 1
    fmt::print(">> Answer 1:\n");
    answer1(input, right, down);

    // Map traversing list
    std::vector<std::vector<uint32_t>> shift_list = 
    {
        {1, 1},
        {3, 1},
        {5, 1},
        {7, 1},
        {1, 2}
    };
    
    // Test answer 2
    fmt::print(">> Test answer 2:\n");
    answer2(test_input, shift_list);

    // Answer 2
    fmt::print(">> Answer 2:\n");
    answer2(input, shift_list);

}
