#include <iostream>
#include <string>
#include <stdexcept>
#include <cctype>

// Function to encode a string using the RLE algorithm
std::string rle_encode(const std::string& input_str) {
    // Check if the input string is empty
    if (input_str.empty()) {
        throw std::invalid_argument("Empty string in input");
    }

    // Check if the string contains only uppercase English characters
    for (char c : input_str) {
        if (!std::isupper(c) || !std::isalpha(c)) {
            throw std::invalid_argument("The string must contain only uppercase English characters");
        }
    }

    // Create a variable to store the encoded string
    std::string encoded_str;

    // Initialize the character repetition counter
    int char_count = 1;

    // Loop through each character in the input string
    for (size_t i = 1; i < input_str.size(); ++i) {
        // Compare the current character with the previous one
        if (input_str[i] == input_str[i - 1]) {
            // Increment the repetition counter
            char_count += 1;
        }
        else {
            // If the current character is different from the previous one
            // Add the previous character and its count to the result (if count > 1)
            encoded_str += input_str[i - 1];
            if (char_count > 1) {
                encoded_str += std::to_string(char_count);
            }
            // Reset the repetition counter
            char_count = 1;
        }
    }

    // Add the last character and its count to the result (if count > 1)
    encoded_str += input_str.back();
    if (char_count > 1) {
        encoded_str += std::to_string(char_count);
    }

    return encoded_str;
}

int main() {
    try {
        std::string input_str = "AAABBCDDDD";
        std::string encoded_str = rle_encode(input_str);
        std::cout << "Encoded string: " << encoded_str << std::endl;
    }
    catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
