// Advent of Code: Day 4
// Lento Manickathan
#include <vector>
#include <string>
#include <fmt/ranges.h>
#include "util.h"

uint32_t problem1(People& people)
{
    uint32_t n_valid = 0;

    for (auto& ipassport: people.passports)
        if ( !( ipassport.byr == "" || 
                ipassport.iyr == "" || 
                ipassport.eyr == "" || 
                ipassport.hgt == "" || 
                ipassport.hcl == "" || 
                ipassport.ecl == "" || 
                ipassport.pid == "" )
            )
            n_valid++;

    return n_valid;

}

uint32_t problem2(People& people)
{
    // Year validity check 
    auto is_yr_valid = [] (std::string yr_str, uint32_t min, uint32_t max)
    {
        bool is_valid = false;
        if (std::isdigit(yr_str[0]) && (yr_str.size() == 4))
        {
            uint32_t yr = std::stoi(yr_str);
            if ((yr >= min) && (yr <= max))
                is_valid = true;
        }
        return is_valid;
    };
   
    // Height check
    auto is_hgt_valid = [] (std::string hgt_str)
    {
        bool is_valid = false;
        if (std::isdigit(hgt_str[0]))
        {
            uint32_t hgt = std::stoi(hgt_str);
            if (strfind(hgt_str, "cm") && (hgt >=150) && (hgt <= 193)) 
                is_valid = true;
            else if (strfind(hgt_str, "in") && (hgt >= 59) && (hgt <= 76))
                is_valid = true;
        }
        return is_valid;
    };

    // Hair color check
    auto is_hcl_valid = [] (std::string hcl_str)
    {
        bool is_valid = false;
        if ((hcl_str[0] == '#') && (hcl_str.size() == 7))
        {
            char n_valid = 0;
            for (char i=1; i<=6; ++i)
                if (std::isxdigit(hcl_str[i]))
                    n_valid++;
            if (n_valid == 6)
                is_valid = true;

        }
        return is_valid;
    };

    // Eye color check
    auto is_ecl_valid = [] (std::string ecl_str)
    {
        const std::vector<std::string> colors = {"amb", "blu", "brn", "gry", "grn", "hzl", "oth"};
        
        return (std::find(colors.begin(), colors.end(), ecl_str) != colors.end()) ? true : false;
    };

    uint32_t n_valid = 0;
    for (auto& ipassport: people.passports)
    {  
        if ( is_yr_valid(ipassport.byr, 1920u, 2002u) && 
             is_yr_valid(ipassport.iyr, 2010u, 2020u) &&
             is_yr_valid(ipassport.eyr, 2020u, 2030u) && 
             is_hgt_valid(ipassport.hgt) && 
             is_hcl_valid(ipassport.hcl) && 
             is_ecl_valid(ipassport.ecl) && 
             (ipassport.pid.size() == 9) )
            n_valid++;
    }

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

    // Test Problem 1:
    uint32_t test_answer1 = problem1(test_people);
    fmt::print(">> Test 1: {}\n", (test_answer1 == 2) ? "PASSED" : "FAILED");
    uint32_t test_answer2 = problem2(test_people);
    fmt::print(">> Test 2: {}\n", (test_answer2 == 2) ? "PASSED" : "FAILED");

    // Solve problem
    Text input("input.txt");
    People people(input);
    fmt::print(">> Answer 1: {}\n", problem1(people)); // 192
    fmt::print(">> Answer 2: {}\n", problem2(people)); // 101

}
