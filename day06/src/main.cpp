// Advent of Code: Day 6
// Lento Manickathan
#include <vector>
#include <string>
#include <chrono>
#include <fmt/ranges.h>
#include "util.h"

struct Group
{
    uint32_t gid;
    std::vector<std::string> text;
    std::vector<uint8_t> people;
    bool a = false;
    bool b = false;
    bool c = false;
    Group(uint32_t gid, std::vector<std::string> text):
        gid(gid),
        text(text)
    {
        // Decode
        for (auto& line : text)
        {
            uint8_t ans = 0;
            for (auto& l: line)
            {
                if (l == 'a')
                {
                    a = true;
                    ans += 1;
                }
                else if (l == 'b')
                {
                    b = true;
                    ans += 2;
                }
                else if (l == 'c')
                {
                    c = true;
                    ans += 4;
                }
            }
            people.push_back(ans);
        }

    };

    inline size_t num_people() const { return people.size(); }

    auto begin() { return people.begin(); }
    auto end() { return people.end(); }
    inline uint32_t count() const { return static_cast<uint32_t>(a) + static_cast<uint32_t>(b) + static_cast<uint32_t>(c); }

    void print() const
    {
        fmt::print("Group {}: Number of people = {}, raw = {}, answer = {}\n",
                gid, num_people(), text, people);
    }
};

std::vector<Group> make_groups(Text& text)
{
    std::vector<Group> groups;
    std::vector<std::string> buffer;
    uint32_t gid = 0;
    for (auto& line : text)
    {
        if (line.size())
            buffer.push_back(line);
        else
        {
            groups.push_back(Group(++gid, buffer));
            buffer = {};
        }
    }
    groups.push_back(Group(++gid, buffer));

    return groups;
}

uint32_t problem1(Text& text)
{
    // Make groups
    std::vector<Group> groups = make_groups(text);

    // Sum of counts
    uint32_t sum_counts = 0;
    for (auto& group : groups)
        sum_counts += group.count();

    return sum_counts;
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
