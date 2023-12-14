#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>
#include <algorithm>


int main() {
    // Open the text file
    std::ifstream inputFile("words.txt");

    // Check if the file is opened successfully
    if (!inputFile.is_open()) {
        std::cerr << "Error opening the file." << std::endl;
        return 1; // Return an error code
    }

    // Create a map to store word frequencies
    std::map<std::string, int> wordFrequencyMap;

    // Read each line from the file
    std::string line;
    while (std::getline(inputFile, line)) {
        // Convert each line to lowercase (optional, to make the comparison case-insensitive)
        std::transform(line.begin(), line.end(), line.begin(), ::tolower);

        // Use a stringstream to extract words from the line
        std::istringstream iss(line);
        std::string word;
        while (iss >> word) {
            // Remove non-alphabetic characters (optional, depending on your requirements)
            word.erase(std::remove_if(word.begin(), word.end(), [](char c) { return !std::isalpha(c); }), word.end());

            // Increment the word frequency in the map
            if (!word.empty()) {
                wordFrequencyMap[word]++;
            }
        }
    }

    // Close the file
    inputFile.close();

    // Print the sorted list of unique words
    std::cout << "Sorted list of unique words:" << std::endl;
    for (const auto& pair : wordFrequencyMap) {
        std::cout << pair.first << " ";
    }
    std::cout << std::endl;

    // Print the associated values (word frequencies)
    std::cout << "Associated values (word frequencies):" << std::endl;
    for (const auto& pair : wordFrequencyMap) {
        std::cout << pair.second << " ";
    }
    std::cout << std::endl;

    return 0;
}
