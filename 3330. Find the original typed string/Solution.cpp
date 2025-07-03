#include <iostream>
using string = std::string;

class Solution {
public:
    int possibleStringCount(string word) 
    {
        int result = 1;          // Mulai dengan 1 kemungkinan
        char behind = '\0';      // Simpan karakter sebelumnya

        for (char c : word) {
            if (c == behind)     // Jika karakter sama dengan sebelumnya
                result++;        // Tambah kemungkinan
            behind = c;          // Update karakter sebelumnya
        }

        return result;           // Kembalikan total kemungkinan

    }
};

int main() {
    Solution solution;
    string word;

    // input
    std::cout << "Enter a string: ";
    std::cin >> word;

    int result = solution.possibleStringCount(word);
    std::cout << "Possible string count for '" << word << "': " << result << std::endl;
    return 0;
}