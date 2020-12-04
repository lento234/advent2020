// Advent of Code: Day 4
// Lento Manickathan
#include <vector>
#include <string>
#include <list>
#include <fmt/ranges.h>
#include "util.h"

uint32_t problem1(People& people)
{
    uint32_t n_valid = 0;
    for (auto& person: people.passports)
        if (person.is_valid())
            n_valid++;

    return n_valid;

}


int main()
{
    // Header info
    constexpr int day = 4;
    fmt::print("//////////////////////////////\n");
    fmt::print("    Advent of Code : Day {}   \n", day);
    fmt::print("//////////////////////////////\n\n");
   
    // Test input
    Text test_input("test_input.txt");
    test_input.print();

    // Test people
    People test_people(test_input);
    //fmt::print("Number of people: {}\n", test_people.num_people());

    // Test Problem 1:
    uint32_t test_answer1 = problem1(test_people);
    fmt::print(">> Test answer 1: {}\n", test_answer1);
    fmt::print(">> Test 1: {}\n", (test_answer1 == 2) ? "PASSED" : "FAILED");

}
