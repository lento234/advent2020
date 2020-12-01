// Advent of Code: Day 1
// Lento Manickathan

#include <iostream>
#include <fstream>
#include <vector>

std::vector<int> load_vector(std::string filename)
{
    std::vector<int> vec;
    std::ifstream file(filename); // Input file stream object
   
    // Check if exists and then open the file.
    if (file.good())
    {
        // Push items into a vector
        int value;
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
    std::cout << "Day: " << day << "\n";
    
    // Read file
    /*
    std::vector<int> numbers;
    std::ifstream file("numbers.txt"); // Input file stream object
   
    // Check if exists and then open the file.
    if (file.good())
    {
        // Push items into a vector
        int value;
        while (file >> value)
            numbers.push_back(value);
    }
    // Close the file.
    file.close();
    */
    std::vector<int> numbers = load_vector("numbers.txt");

    // Print array
    std::cout << "array: ";
    for (auto& i: numbers)
        std::cout << i << " ";
    std::cout << "\n";

}
