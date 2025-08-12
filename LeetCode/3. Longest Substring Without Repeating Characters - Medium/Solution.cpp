#include <iostream>

// #include <iomanip>

// #include <vector>
// using std::vector;

// #include <unordered_map>

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
    int lengthOfLongestSubstring(string s) {
        string ans = "";
        int high = 0;

        for (int i = 0; i < s.size(); i++) {
            size_t pos = ans.find(s[i]);       // Cari karakter s[i] di substring ans
            if (pos != string::npos) {
                ans.erase(0, pos + 1);         // Hapus karakter dari awal sampai karakter duplikat
            }
            ans.push_back(s[i]);               // Tambahkan karakter baru ke substring
            if (ans.size() >= high)            // Update panjang maksimum jika perlu
                high = ans.size();
        }

        return high;
    }
};

int main() {
    Solution solution;
    string text;

    std::cout << "Input Word : " << CYAN;
    std::getline(std::cin, text); RESETL
    
    int result = solution.lengthOfLongestSubstring(text);
    NewLine

    std::cout << "Longest unique substring character is " << GREEN << result << RESET << ".";
    NewLine

    return 0;
}