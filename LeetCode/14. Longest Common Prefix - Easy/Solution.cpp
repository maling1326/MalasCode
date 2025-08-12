#include <iostream>
#include <chrono>
#include "../etc/debug.h"

// #include <iomanip>

#include <vector>
using std::vector;

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

vector<string> stringToArray (string s);

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
    string longestCommonPrefix(vector<string>& strs) {
        // Loop setiap karakter pada string pertama
        for (int i = 0; i < strs[0].size(); i++) {
            char c = strs[0][i];  // Ambil karakter ke-i dari string pertama
            
            // Cek karakter ke-i pada semua string lain
            for (int j = 0; j < strs.size(); j++) {
                // Jika indeks i melebihi panjang string ke-j atau karakter berbeda
                if (i >= strs[j].size() || strs[j][i] != c)
                    // Kembalikan prefix sampai sebelum karakter ke-i
                    return strs[0].substr(0, i);
            }
        }
        
        // Jika semua karakter cocok sampai akhir string pertama, kembalikan string pertama
        return strs[0];
    }
};


int main() {
    Stopwatch sw;
    Solution solution;

    string word;

    std::cout << "Cek Prefix Terpanjang, Pisahkan dengan ',' atau ' '.\n| Input  : " << CYAN;
    getline(std::cin, word); RESETL

    vector<string> words = stringToArray(word);
    
    sw.start();
    word = solution.longestCommonPrefix(words);
    int time = sw.stop();

    std::cout << "| Prefix : " << GREEN << word << RESET; NewLine
    std::cout << "| Time Elapsed : " << YELLOW << time << RESET; NewLine

    return 0;
}

vector<string> stringToArray(string s)
{
    vector<string> result;
    int begin = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ',' || s[i] == ' ' || i == s.size() - 1) {
            result.push_back(s.substr(begin, i));
            begin = i + 1;
        }
    }
    return result;
}
