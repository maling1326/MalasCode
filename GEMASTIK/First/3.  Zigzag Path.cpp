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

// #include <string>
// using std::string;

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
    // Paste Function here
};

/*
pake for loop
klo ganjil horizontal
klo genap vertikal
*/

int main() {
    Stopwatch sw;
    Solution solution;
    
    // sw.start();
    // int time = sw.stop();

    int X = 0, Y = 0, XX, YY, i = 0;
    std::cin >> XX >> YY;
    
    while (X != XX || Y != YY) {
        if (i % 2 == 0) {
            X += (X < XX) ? 1 : -1;
        } else {
            Y += (Y < YY) ? 1 : -1;
        }
        std::cout << X << " " << Y << '\n';
        i++;
    }
    

    return 0;
}