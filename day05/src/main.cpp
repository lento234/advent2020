// Advent of Code: Day 5
// Lento Manickathan
#include <vector>
#include <string>
#include <chrono>
#include <fmt/ranges.h>
#include "util.h"

constexpr int decode(const char& c)
{ 
    return (c=='F' or c=='L') ? 1 : 0;
}

inline uint32_t bsp(const std::string code, uint32_t max)
{
    uint32_t min = 0;
    for (size_t i=0; i<code.size(); ++i)
    {
        if (decode(code[i]))
            max -= (max-min)/2 + 1;
        else        
            min += (max-min)/2 + 1;
    }

    return min;
}

uint32_t problem1(Text& text)
{
    constexpr uint32_t partition = 7;
    uint32_t highest_seatID = 0;
    for (auto& line: text)
    {
        uint32_t row = bsp(line.substr(0, partition), 127);
        uint32_t col = bsp(line.substr(partition), 7);
        uint32_t seat = row * 8 + col;
        highest_seatID = std::max(seat, highest_seatID);
    }
    return highest_seatID;
}

uint32_t problem2(Text& text)
{
    // Get search IDs
    constexpr uint32_t partition = 7;
    std::vector<uint32_t> seats;
    for (auto& line: text)
    {
        uint32_t row = bsp(line.substr(0, partition), 127);
        uint32_t col = bsp(line.substr(partition), 7);
        uint32_t seat = row * 8 + col;
        seats.push_back(seat);
    }
    std::sort(seats.begin(), seats.end());
    
    // Find missing seat
    uint32_t next_seat = seats[0]+1;
    for (size_t i=1; i<seats.size(); ++i)
    {
        if (next_seat != seats[i])
            return next_seat;
        next_seat = seats[i]+1;
    }
    return -1;
}

int main()
{
    auto start = std::chrono::high_resolution_clock::now();

    // Header info
    constexpr int day = 5;
    fmt::print("//////////////////////////////\n");
    fmt::print("    Advent of Code : Day {}   \n", day);
    fmt::print("//////////////////////////////\n\n");
   
    // Test input
    Text test_input("test_input.txt");
    test_input.print();

    // Test Problem 1
    uint32_t test_answer1 = problem1(test_input);
    uint32_t test_answer2 = problem2(test_input);
    fmt::print(">> Test 1: Highest seat ID = {}    [{}]\n", test_answer1, (test_answer1 == 820) ? "PASSED" : "FAILED");
    fmt::print(">> Test 2: First missing seat = {} [{}]\n", test_answer2, (test_answer2 == 120) ? "PASSED" : "FAILED");
    problem2(test_input);

    // Solve problem
    Text input("input.txt");
    fmt::print(">> Answer 1: {}\n", problem1(input));
    problem2(input);
    fmt::print(">> Answer 2: {}\n", problem2(input)); 

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end-start;
    fmt::print("\nTotal duration: {:.3f} ms\n", diff.count() * 1000);

}
