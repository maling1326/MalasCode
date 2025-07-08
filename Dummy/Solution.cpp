#include <iostream>
#include <chrono>
#include "../debug.h"

// #include <iomanip>

// #include <vector>
// using std::vector;

// #include <unordered_map>
// using std::unordered_map;

// #include <map>
// using std::map;

// #include <algorithm>
// #define all(v) v.begin(), v.end()

// #include <string>
// using std::string;

// ANSI color codes for colored terminal output
#define CYAN    "\033[36m"
#define GREEN   "\033[32m"
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
        std::cout << "Total Runtime : " << GREEN << duration.count(); RESETL NewLine
    }
};

class Solution {
public:
    // Paste Function here
};

int main() {
    Stopwatch sw;
    Solution solution;
    
    // sw.start();
    // sw.stop();

    return 0;
}