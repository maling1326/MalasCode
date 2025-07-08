#include <iostream>
#include <chrono>

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

vector<int> StringToVectorInt(std::string text);

class Solution {
public:
    int findLucky(vector<int>& arr) {
        int nums[501] = {0};  // Array untuk menghitung frekuensi angka (1 sampai 500)

        for (int n : arr) 
            nums[n]++;       // Hitung kemunculan setiap angka dalam arr

        for (int i = 500; i > 0; i--) {
            if (nums[i] == i) // Cek apakah frekuensi sama dengan angka itu sendiri
                return i;     // Kembalikan angka terbesar yang memenuhi kondisi
        }

        return -1;            // Jika tidak ada angka yang memenuhi, kembalikan -1
    }
};


int main() {
    Stopwatch sw;
    Solution solution;

    std::string input;

    std::cout << "Input Numbers separated by ',' or ' ' : " << CYAN;
    getline(std::cin, input); RESETL
    
    vector<int> num = StringToVectorInt(input);

    sw.start();
    int lucky_num = solution.findLucky(num);
    sw.stop();

    std::cout << "Lucky Integer is : " << GREEN << lucky_num << RESET << ".";
    NewLine

    return 0;
}

vector<int> StringToVectorInt(std::string text)
{
    std::string temp = "0";
    vector<int> v;
    for (int i = 0; i < text.size(); i++) {
        if (text[i] == ',' || text[i] == ' ') {
            v.push_back(std::stoi(temp));
            temp.clear();
            continue;
        }
        temp.push_back(text[i]);
    }
    v.push_back(std::stoi(temp));
    
    return v;
}
