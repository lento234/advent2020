// Advent of Code: Day 7
// Lento Manickathan
#include <map>
#include <vector>
#include <string>
#include <chrono>
#include <fmt/ranges.h>
#include "util.h"

using fmt::print;

class Bag
{
public:
    //std::map<std::string, Bag> bags;
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

    void operator<<(std::string&& child_name) { bags.emplace_back(child_name, level+1); }

    inline auto begin() {return bags.begin(); }
    inline auto end() {return bags.end(); }

    void print()
    {
        fmt::print("{}{}{} {} : [level = {}, total = {}, size = {}]\n",
                std::string(level*2, ' '), level ? "└": "", std::string(level,'>'),
                name, level, total_size(), size());
        for (auto& bag : bags)
            bag.print();
    }

};



uint32_t problem1(Text& text)
{
    for (auto& line : text)
    {
        auto pos = line.find("shiny gold");
        if (pos != std::string::npos)
            fmt::print("{}, {}\n", line, pos);
    }
    
    Bag shiny_gold = {"shiny gold bag"};

    

    /*
    shiny_gold << "purple";
    shiny_gold << "red";
    shiny_gold[0] << "green";
    shiny_gold[0] << "green";
    shiny_gold[0] << "yellow";
    shiny_gold[0][0] << "gray";
    shiny_gold[0] << "blue";
    shiny_gold[1] << "orange";
    shiny_gold[1][0] << "magenta";

    shiny_gold.print();
    */
    
    std::map<std::string, Bag> map;
   
    Bag temp = {"purple"};
    map.insert(std::make_pair("purple", temp)); // (std::make_pair("purple", Bag("purple"))); //Bag("purple");
    //map.insert(std::make_pair("red", 2));
    //map.insert(std::make_pair("green", 3));

    //print("     {}\n", map["purple"]);
    //print("map = {}\n", map["purple"]);
    //
    //    print("{}, {}\n", map["purple"].name, map["purple"].level);

    /*
    print("c = {}\n", map["c"]);
    */
    //print("Bag = {}, level = {}, size = {}\n", shiny_gold_bag.name, shiny_gold_bag.level, shiny_gold_bag.total_size());

    return 0;
}



int main()
{
    auto start = std::chrono::high_resolution_clock::now();

    // Header info
    constexpr uint8_t day = 6;
    print("//////////////////////////////\n");
    print("    Advent of Code : Day {}   \n", day);
    print("//////////////////////////////\n\n");
  
    // Test input
    Text test_input("test_input.txt");
    test_input.print();

    // Test Problem 1
    uint32_t test_answer1 = problem1(test_input);
    print(">> Test 1: Sum of counts = {} ({}) [{}]\n",
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
    print("\nTotal duration: {:.3f} ms\n", duration.count());

}
