// Advent of Code: Day 3
// Lento Manickathan

#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <fmt/ranges.h>
#include "util.h"

//std::vector<uint32_t> 
static void decode_input(const std::vector<std::string> input)
{
    size_t N = input.size();
    size_t M = input[0].size();

    // Decode message
    bool message[N][M];
    for (size_t i=0; i<N; ++i)
        for (size_t j=0; j<M; ++j)
            message[i][j] = (input[i][j] == '.') ? false : true;

    fmt::print("message: {}", message[0][0]);
}

int main()
{
    // Info
    const int day = 3;
    fmt::print("Advent of Code : Day {}\n", day);

    // Read file
    auto test_input = read_file("test_input.txt");

    // Print content
    fmt::print("{}\n", fmt::join(test_input, "\n"));

    decode_input(test_input);

}
