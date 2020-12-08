// Advent of Code: Day 6
// Lento Manickathan
#include <algorithm>
#include <iterator>
#include <memory>
#include <set>
#include <list>
#include <vector>
#include <string>
#include <chrono>
#include <fmt/ranges.h>
#include "util.h"


class Bag
{
public:
    std::vector<Bag> bags;
    std::string name;
    uint32_t level;

    Bag (std::string name, uint32_t level=0) : name(name), level(level) {};

    size_t total_size()
    { 
        size_t size = 1;
        for (auto& bag : bags)
            size += bag.total_size();
        return size;
    }
    
    size_t size() const { return bags.size(); }

    inline Bag& operator[](const size_t i) { return bags[i]; }

    void operator<<(std::string&& child_name) { bags.emplace_back(Bag(child_name, level+1)); }

    inline auto begin() {return bags.begin(); }
    inline auto end() {return bags.end(); }

    void print()
    {
        fmt::print("{}|{} {} : [level = {}, total = {}, size = {}]\n",
                std::string(level*2, ' '), std::string(level, '-'),
                name, level, total_size(), size());
        for (auto& bag : bags)
            bag.print();
    }

};



uint32_t problem1(Text& text)
{
    for (auto& line : text)
    {
        auto pos = line.find("shiny gold bag");
        if (pos != std::string::npos)
        {
            fmt::print("{}, {}\n", line, pos);
        }
    }

    /*
    Bag shiny_gold_bag = {"shiny gold bag"};

    shiny_gold_bag << "purple";
    shiny_gold_bag << "red";
    shiny_gold_bag.bags[0] << "green";
    shiny_gold_bag.bags[0] << "yellow";
    shiny_gold_bag.bags[0] << "blue";
    shiny_gold_bag.bags[1] << "orange";

    shiny_gold_bag.print();
    */

    fmt::print("Bag = {}, level = {}, size = {}\n", shiny_gold_bag.name, shiny_gold_bag.level, shiny_gold_bag.total_size());

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
