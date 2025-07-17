#include <iostream>
#include <chrono>
// #include "../etc/debug.h"

// #include <iomanip>

// #include <vector>
// using std::vector;

// #include <unordered_map>
// using std::unordered_map;

// #include <map>
// using std::map;

// #include <algorithm>
// #define all(v) v.begin(), v.end()

#include <string>
using std::string;

// ANSI color codes for colored terminal output
#define RED    "\033[31m"
#define GREEN   "\033[32m"
#define CYAN    "\033[36m"

#define BOLD      "\033[1m"
#define ITALIC    "\033[3m"
#define UNDERLINE "\033[4m"
#define BLINK     "\033[6m"

#define RESET   "\033[0m"

// Macros for resetting color and printing new line
#define RESETL  std::cout << "\033[0m";
#define NewLine std::cout << "\n";

class Stopwatch {
    using clock = std::chrono::high_resolution_clock;
    std::chrono::time_point<clock> start_time;
    bool running = false;

public:
    // Mulai stopwatch
    void start() {
        start_time = clock::now();
        running = true;
    }

    // Hentikan stopwatch dan kembalikan durasi dalam milidetik
    void stop() {
        if (!running) std::cout << "Total Runtime : " << GREEN << 0; RESETL NewLine // Jika belum start, kembalikan 0
        auto end_time = clock::now();
        running = false;
        // Hitung durasi dalam milidetik
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
        std::cout << "Total Runtime : " << GREEN << duration.count() << RESET << " ms"; NewLine
    }
};

class Solution {
public:
    bool isPalindrome(int x) {
        string nums = std::to_string(x);  // Konversi angka ke string
        for (int i = 0; i < nums.size() / 2; i++) {
            if (nums[i] != nums[nums.size() - i - 1])  // Bandingkan karakter depan & belakang
                return false;  // Bukan palindrome
        }
        return true;  // Palindrome
    }
};


int main() {
    Stopwatch sw;
    Solution solution;
    
    int nums;

    std::cout << "Cek Angka : " << CYAN;
    std::cin  >> nums; RESETL

    NewLine

    sw.start();
    bool check = solution.isPalindrome(nums);
    sw.stop();

    if (check)
        std::cout << "Angka " << CYAN << nums << RESET << ", " << GREEN << BOLD << "Merupakan " << RESET << "Palindrom.";
    else
        std::cout << "Angka " << CYAN << nums << RESET << ", " << RED << BOLD << "Bukanlah " << RESET << "Palindrom.";


    return 0;
}