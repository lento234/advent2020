// Advent of Code: Day 6
// Lento Manickathan
#include <algorithm>
#include <iterator>
#include <set>
#include <list>
#include <vector>
#include <string>
#include <chrono>
#include <fmt/ranges.h>
#include "util.h"


uint32_t problem1(Text& text)
{

    return 0;
}



int main()
{
    auto start = std::chrono::high_resolution_clock::now();

    // Header info
    constexpr uint8_t day = 6;
    fmt::print("//////////////////////////////\n");
    fmt::print("    Advent of Code : Day {}   \n", day);
    fmt::print("//////////////////////////////\n\n");
  
    // Test input
    Text test_input("test_input.txt");
    test_input.print();

    // Test Problem 1
    uint32_t test_answer1 = problem1(test_input);
    fmt::print(">> Test 1: Sum of counts = {} ({}) [{}]\n",
            test_answer1, 4, (test_answer1 == 4) ? "PASSED" : "FAILED");
    //uint32_t test_answer2 = problem2(test_input);
    //fmt::print(">> Test 2: Sum of counts = {} ({}) [{}]\n",
    //        test_answer2, 6, (test_answer2 == 6) ? "PASSED" : "FAILED");

    //// Solve problem
    //Text input("input.txt");
    //fmt::print(">> Answer 1: {}\n", problem1(input));
    //fmt::print(">> Answer 2: {}\n", problem2(input));

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration<double, std::milli>(end - start);
    fmt::print("\nTotal duration: {:.3f} ms\n", duration.count());

}
