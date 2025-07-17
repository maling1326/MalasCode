#include <iostream>

// #include <vector>
// using std::vector;

#include <string>
using std::string;

// ANSI color codes for colored terminal output
#define CYAN    "\033[36m"
#define GREEN   "\033[32m"
#define RESET   "\033[0m"

// Macros for resetting color and printing new line
#define RESETL  std::cout << "\033[0m";
#define NewLine std::cout << "\n";

class Solution {
public:
    int strStr(string haystack, string needle) {
        size_t val = haystack.find(needle, 0);
        if (val != std::string::npos)
            return val;
        else
            return -1;
    }
};

int main() {
    Solution solution;
    string text, find;

    std::cout << "Input Word   : " << CYAN;
    std::cin  >> text; RESETL

    std::cout << "What to Find : " << CYAN;
    std::cin  >> find; RESETL

    int val = solution.strStr(text, find);
    NewLine

    if (val == -1)
        std::cout << GREEN << "DOES NOT" << RESET << " Occure";
    else 
        std::cout << "Occure : " << GREEN << val << RESET;

    return 0;
}