#pragma once

#include <string>
#include <vector>
#include <list>
#include <fstream>
#include <sstream>
#include <fmt/ranges.h>

struct Text
{
    std::vector<std::string> raw;

    Text(const std::string& filename)
    {
        // Read file
        std::ifstream file(filename);
        if (!file.good())
            throw std::runtime_error("Failed to open!");

        // Buffer file
        std::string buffer;
        while (getline(file, buffer))
            raw.push_back(buffer);
        file.close();

    }

    size_t size() { return raw.size(); }

    void print()
    {
        fmt::print("    {}\n\n", fmt::join(raw, "\n    "));
    }

};

struct Passport
{
    
    uint32_t byr = 0; // Birth year
    uint32_t iyr = 0; // Issue year
    uint32_t eyr = 0; // Expiration year
    uint32_t hgt = 0; // Height
    std::string hcl = ""; // Hair color
    std::string ecl = ""; // Eye color
    uint64_t pid = 0; // Passport ID
    uint32_t cid = 0; // Country ID

    Passport(const std::vector<std::string>& info)
    {
        // Make passport
        std::string buffer;
        for (auto& iinfo : info)
        {
            const std::string key = iinfo.substr(0, iinfo.find(':'));
            const std::string value = iinfo.substr(iinfo.find(':')+1);
            if (key == "byr")
                byr = std::stoi(value);
            else if (key == "iyr")
                iyr = std::stoi(value);
            else if (key == "eyr")
                eyr = std::stoi(value);
            else if (key == "hgt")
                hgt = std::stoi(value);
            else if (key == "hcl")
                hcl = value;
            else if (key == "ecl")
                ecl = value;
            else if (key == "pid")
                pid = std::stoi(value);
            else if (key == "cid")
                cid = std::stoi(value);
        }
    }

    void print()
    {
        fmt::print("Info: byr = {}, iyr = {}, eyr = {}, hgt = {} cm, hcl = {}, ecl = {}, pid = {}, cid = {}\n",
                byr, iyr, eyr, hgt, hcl, ecl, pid, cid);
    }

    inline bool is_valid()
    {
        if (byr == 0 || iyr == 0 || eyr == 0 || hgt == 0 || hcl == "" || ecl == "" || pid == 0)
            return false;
        else
            return true;
    }

};

struct People
{
    std::vector<Passport> passports;

    People(const Text& text)
    {
        std::vector<std::string> buffer;
        for (auto& line: text.raw)
        {
            if (line.size() == 0)
            {
                passports.push_back(Passport(buffer));
                buffer = {};
            }
            else
            {
                std::istringstream line_stream(line);
                for(std::string each; getline(line_stream, each, ' '); buffer.push_back(each)); 
            }
        }
        passports.push_back(Passport(buffer));
    }
    size_t num_people() { return passports.size(); }


};


