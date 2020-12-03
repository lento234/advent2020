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

template<typename T>
void answer1(std::vector<T>& numbers)
{
    std::cout << "Answer 1:\n";
    for (auto& a: numbers)
        for (auto& b: numbers)
            if (a+b == 2020)
            {
                std::cout << a << "+" << b << "=" << a+b << "\n"
                          << a << "*" << b << "=" << a*b << "\n";
                return;
            }
}

template<typename T>
void answer2(std::vector<T>& numbers)
{
    std::cout << "Answer 2:\n";
    for (auto& a: numbers)
        for (auto& b: numbers)
            for (auto& c: numbers)
                if (a+b+c == 2020)
                {
                    std::cout << a << "+" << b << "+" << c << "=" << a+b+c << "\n"
                              << a << "*" << b << "+" << c << "=" << a*b*c << "\n";
                     return;
                }
}


int main()
{
    // Info
    const unsigned int day = 1;
    std::cout << "Advent of Code : Day " << day << "\n";
    
    // Read file
    std::vector<int> numbers = load_vector<int>("numbers.txt");

    // Answer 1
    answer1(numbers);
   
    // Answer 2
    answer2(numbers);

}
