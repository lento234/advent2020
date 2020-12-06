// Advent of Code: Day 6
// Lento Manickathan
#include <vector>
#include <string>
#include <chrono>
#include <fmt/ranges.h>
#include "util.h"

inline uint8_t decode(char& c)
{
    if (c == 'a')
        return 1;
    else if (c == 'b')
        return 2;
    else if (c == 'c')
        return 4;
    else
        return 0;
}

struct Group
{
    uint32_t gid;
    std::vector<std::string> raw;
    std::vector<uint8_t> answer;
    Group(uint32_t gid, std::vector<std::string> people):
        gid(gid),
        raw(people)
    {
        // Decode
        for (auto& line : people)
        {
            uint8_t ans = 0;
            for (auto& c : line)
                ans += decode(c);
            answer.push_back(ans);
        }

    };

    inline size_t num_people() const { return answer.size(); }

    auto begin() { return answer.begin(); }
    auto end() { return answer.end(); }

    void print() const
    {
        fmt::print("Group {}: Number of people = {}, raw = {}, answer = {}\n", gid, num_people(), raw, answer);
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

    // Debug
    //for (auto& group : groups)
    //    group.print();

    // Check at least all answer
    uint32_t num_valid_groups = 0;
    for (auto& group : groups)
    {
        uint32_t sum_answer = 0;
        for (auto& person : group)
        {
            if ((person == 1) or (person = 2) or (person == 4))
                sum_answer = 1;


        }
        fmt::print("Group {}: Number of people = {}, Number of answers = {}\n", group.gid, group.num_people(), sum_answer);
    }
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
