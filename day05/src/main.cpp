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

void answer1(Text& text)
{
    for (auto& line: text)
    {
        int message=0;
        for (int i=0; i<10; ++i)
        {
            int decoded = decode(line[i]);
            message += pow(2, i)*decoded;
            fmt::print("{}", decoded);
        }
        fmt::print("    = {}\n", message);
    }
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
    answer1(test_input);
    //uint32_t test_answer1 = problem1(test_people);
    //fmt::print(">> Test 1: {}\n", (test_answer1 == 2) ? "PASSED" : "FAILED");
    //uint32_t test_answer2 = problem2(test_people);
    //fmt::print(">> Test 2: {}\n", (test_answer2 == 2) ? "PASSED" : "FAILED");

    // Solve problem
    //Text input("input.txt");
    //fmt::print(">> Answer 1: {}\n", problem1());
    //fmt::print(">> Answer 2: {}\n", problem2()); 

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end-start;
    fmt::print("Total duration: {:.3f} ms\n", diff.count() * 1000);

}
