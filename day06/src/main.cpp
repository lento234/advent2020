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

struct Group
{
    uint32_t gid;
    std::vector<std::string> text;
    std::vector<std::vector<char>> people;
    std::set<char> group_answers;
    Group(uint32_t gid, std::vector<std::string> text):
        gid(gid),
        text(text)
    {

        // Decode
        for (auto& line : text)
        {
            std::set<char> answer;
            for (auto& l: line)
            {
                answer.insert(l);
                group_answers.insert(l);
            }
            std::vector<char> answer_v(answer.begin(), answer.end());
            people.push_back(answer_v);
        }
    }

    inline size_t num_people() const { return people.size(); }

    inline size_t size() const { return num_people(); }

    inline size_t count() const { return group_answers.size(); }
    
    auto begin() { return people.begin(); }
    auto end() { return people.end(); }

    void print() const
    {
        fmt::print("Group {}: Number of people = {}, raw = {}, answers = {}\n",
                gid, num_people(), text, group_answers);
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

uint32_t problem2(Text& text)
{
    // Make groups
    std::vector<Group> groups = make_groups(text);

    // Debug
    uint32_t sum_counts = 0;
    for (auto& group : groups)
    {
        if (group.num_people() == 1)
            sum_counts += group.count();
        else
        {
            std::vector<char> intersect;
            for (size_t i=0; i<group.size()-1; ++i)
                 std::set_intersection(group.people[i].begin(), group.people[i].end(),
                            group.people[i+1].begin(), group.people[i+1].end(), std::back_inserter(intersect));
            auto last = std::unique(intersect.begin(), intersect.end());
            intersect.erase(last, intersect.end());
            sum_counts += intersect.size();
        }
    }
    
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
    uint32_t test_answer2 = problem2(test_input);
    fmt::print(">> Test 2: Sum of counts = {} ({}) [{}]\n",
            test_answer2, 6, (test_answer2 == 6) ? "PASSED" : "FAILED");

    // Solve problem
    //Text input("input.txt");
    //fmt::print(">> Answer 1: {}\n", problem1(input));

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration<double, std::milli>(end - start);
    fmt::print("\nTotal duration: {:.3f} ms\n", duration.count());

}
