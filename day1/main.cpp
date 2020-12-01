// Advent of Code: Day 1
// Lento Manickathan

#include <iostream>
#include <fstream>
#include <vector>

template<typename T>
std::vector<T> load_vector(std::string filename)
{
    std::vector<T> vec;
    std::ifstream file(filename); // Input file stream object
   
    // Check if exists and then open the file.
    if (file.good())
    {
        // Push items into a vector
        T value;
        while (file >> value)
            vec.push_back(value);
    }
    // Close the file.
    file.close();

    return vec;
}

int main()
{
    // Info
    const unsigned int day = 1;
    std::cout << "Advent of Code : Day " << day << "\n";
    
    // Read file
    std::vector<int> numbers = load_vector<int>("numbers.txt");

    // Print array
    std::cout << "Solution:\n";
    for (auto& a: numbers)
        for (auto& b: numbers)
            if (a+b == 2020)
            {
                std::cout << a << " + " << b << " = " << a + b << "\n"
                          << a << " * " << b << " = " << a * b << "\n";
                return 0;
            }

}
