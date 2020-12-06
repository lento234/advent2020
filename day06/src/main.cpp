// Advent of Code: Day 6
// Lento Manickathan
#include <vector>
#include <string>
#include <chrono>
#include <fmt/ranges.h>
#include "util.h"

uint32_t problem1(const Text& text)
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
            test_answer1, 11, (test_answer1 == 11) ? "PASSED" : "FAILED");

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration<double, std::milli>(end - start);
    fmt::print("\nTotal duration: {:.3f} ms\n", duration.count());

}
