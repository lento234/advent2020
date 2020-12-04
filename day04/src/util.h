#pragma once

#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <fstream>
#include <sstream>
#include <fmt/ranges.h>

inline bool strfind(std::string& value, std::string pattern)
{
    return (value.find(pattern) != std::string::npos);
}

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
    
    std::string byr = ""; // Birth year
    std::string iyr = ""; // Issue year
    std::string eyr = ""; // Expiration year
    std::string hgt = ""; // Height
    std::string hcl = ""; // Hair color
    std::string ecl = ""; // Eye color
    std::string pid = ""; // Passport ID
    std::string cid = ""; // Country ID

    Passport(const std::vector<std::string>& info)
    {
        std::string buffer;
        for (auto& iinfo : info)
        {
            const std::string key = iinfo.substr(0, iinfo.find(':'));
            const std::string value = iinfo.substr(iinfo.find(':')+1);
            if (key == "byr")
                byr = value;
            else if (key == "iyr")
                iyr = value;
            else if (key == "eyr")
                eyr = value;
            else if (key == "hgt")
                hgt = value;
            else if (key == "hcl")
                hcl = value;
            else if (key == "ecl")
                ecl = value;
            else if (key == "pid")
                pid = value;
            else if (key == "cid")
                cid = value;
        }
    }

    void print()
    {
        fmt::print("Info: byr = {}, iyr = {}, eyr = {}, hgt = {}, hcl = {}, ecl = {}, pid = {}, cid = {}\n",
                byr, iyr, eyr, hgt, hcl, ecl, pid, cid);
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


