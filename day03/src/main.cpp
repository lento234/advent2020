// Advent of Code: Day 3
// Lento Manickathan
#include <vector>
#include <string>
#include <list>
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

uint32_t problem1(const Message& input, const uint32_t& right = 3, const uint32_t& down = 1)
{
    uint32_t n_trees = count_trees(input, right, down);
    
    return n_trees;
}

uint64_t problem2(const Message& input, const std::list<std::pair<uint32_t, uint32_t>>& shift_list)
{
    uint64_t product = 1;
    for (const auto& [right, down]: shift_list)
        product *= count_trees(input, right, down);
    
    return product;
}

int main()
{
    // Header info
    constexpr int day = 3;
    fmt::print("//////////////////////////////\n");
    fmt::print("    Advent of Code : Day {}   \n", day);
    fmt::print("//////////////////////////////\n\n");

    // Test input
    Message test_input("test_input.txt");
    
    // Test Problem 1:
    constexpr uint32_t right = 3, down = 1; // shift index
    uint32_t test_answer1 = problem1(test_input, right, down);
    fmt::print(">> Test answer 1: {}\n", test_answer1);
    fmt::print(">> Test 1: {}\n", (test_answer1 == 7) ? "PASSED" : "FAILED");

    // Test Problem 2:
    const std::list<std::pair<uint32_t, uint32_t>> shift_list = 
    {
        {1, 1}, // right, down
        {3, 1},
        {5, 1},
        {7, 1},
        {1, 2}
    };
    
    uint32_t test_answer2 = problem2(test_input, shift_list);
    fmt::print(">> Test answer 2: {}\n", test_answer2);
    fmt::print(">> Test 2: {}\n", (test_answer2 == 336) ? "PASSED" : "FAILED");

    // Solve problem
    Message input("input.txt"); // read message
    fmt::print(">> Answer 1: {}\n", problem1(input, right, down));
    fmt::print(">> Answer 2: {}\n", problem2(input, shift_list));

}
