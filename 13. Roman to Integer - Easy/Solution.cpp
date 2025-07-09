#include <iostream>
#include <chrono>
#include "../etc/debug.h"

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
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
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
    int stop() {
        if (!running) {std::cout << "Total Runtime : " << GREEN << 0; RESETL NewLine} // Jika belum start, kembalikan 0
        auto end_time = clock::now();
        running = false;
        // Hitung durasi dalam milidetik
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
        return duration.count();
    }
};

class Solution {
public:
    int romanToInt(string s) {
        int sum = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'C' && s[i+1] == 'M')       // CM
                {sum += 900; i++;}
            else if (s[i] == 'C' && s[i+1] == 'D')  // CD
                {sum += 400; i++;}
            else if (s[i] == 'X' && s[i+1] == 'C')  // XC
                {sum += 90; i++;}
            else if (s[i] == 'X' && s[i+1] == 'L')  // XL
                {sum += 40; i++;}
            else if (s[i] == 'I' && s[i+1] == 'X')  // IX
                {sum += 9; i++;}
            else if (s[i] == 'I' && s[i+1] == 'V')  // IV
                {sum += 4; i++;}
            else if (s[i] == 'M')                   // M
                sum += 1000;
            else if (s[i] == 'D')                   // D
                sum += 500;
            else if (s[i] == 'C')                   // C
                sum += 100;
            else if (s[i] == 'L')                   // L
                sum += 50;
            else if (s[i] == 'X')                   // X
                sum += 10;
            else if (s[i] == 'V')                   // V
                sum += 5;
            else if (s[i] == 'I')                   // I
                sum += 1;
        }

        return sum;
    }
};

int main() {
    Stopwatch sw;
    Solution solution;
    
    string roman;
    std::cout << "| Convert Romans to Integer\n|  Roman  : " << CYAN;
    getline(std::cin, roman); RESETL

    // Convert to lowercase
    for (char &c : roman) c = toupper(c);
    
    sw.start();
    int num = solution.romanToInt(roman);
    int time = sw.stop();
    
    std::cout << "|  Number : " << GREEN << num << RESET; NewLine
    std::cout << "|  Time Elapsed : " << YELLOW << time << RESET << " ms";
    
    NewLine
    return 0;
}