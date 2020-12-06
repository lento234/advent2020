// Advent of Code: Day 6
// Lento Manickathan
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
    std::list<std::list<uint8_t>> people;
    std::list<uint8_t> group_answers;
    Group(uint32_t gid, std::vector<std::string> text):
        gid(gid),
        text(text)
    {

        // Decode
        for (auto& line : text)
        {
            std::list<uint8_t> answer;
            for (auto& l: line)
            {
                answer.push_back(static_cast<size_t>(l)-97);
                group_answers.push_back(static_cast<size_t>(l)-97);
            }
            answer.sort();
            answer.unique();
            people.push_back(answer);
        }

        // group answer
        group_answers.sort();
        group_answers.unique();
    }

    inline size_t num_people() const { return people.size(); }

    auto begin() { return people.begin(); }
    auto end() { return people.end(); }

    void print() const
    {
        fmt::print("Group {}: Number of people = {}, raw = {}, answers = {}\n",
                gid, num_people(), text, group_answers);
    }

    size_t count() const
    {
        fmt::print("Group {}: count = {}\n", gid, group_answers.size());
        return group_answers.size();
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

    for (auto& group : groups)
        group.print();

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

    fmt::print("a={}, e={}, m={}, z={}\n", uint8_t('a'), 'e', 'm' , uint8_t('z'));

    // Test Problem 1
    uint32_t test_answer1 = problem1(test_input);
    fmt::print(">> Test 1: Sum of counts = {} ({}) [{}]\n",
            test_answer1, 11, (test_answer1 == 11) ? "PASSED" : "FAILED");

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration<double, std::milli>(end - start);
    fmt::print("\nTotal duration: {:.3f} ms\n", duration.count());

}
