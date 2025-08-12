#include <iostream>

// ANSI color codes for colored terminal output
#define CYAN    "\033[36m"
#define GREEN   "\033[32m"
#define RESET   "\033[0m"

// Macros for resetting color and printing new line
#define RESETL  std::cout << "\033[0m";
#define NewLine std::cout << "\n";

class Solution {
public:
    
    long long climbStairs(const int& n) 
    {
        // Inisialisasi awal
        long long result, x = 0, y = 1;
        
        // Hitung jumlah cara naik tangga ke-n (mirip Fibonacci)
        for (int i = 0; i < n; i++) {
            result = x + y;  // jumlah cara ke langkah sekarang
            x = y;           // geser nilai sebelumnya
            y = result;      // update nilai terbaru
        }
        
        return result;       // hasil akhir: jumlah cara naik ke anak tangga ke-n
    }

};

int main() {
    int n;
    long long ans;
    Solution solution;
    
    std::cout << "Iterasi Fibonacci ke : " << CYAN;
    std::cin  >> n; RESETL 
    
    NewLine

    ans = solution.climbStairs(n);

    std::cout << "Fibonacci ke-" << GREEN << n << RESET << " adalah " << CYAN << ans << RESET << "."; 
    
    NewLine

    return 0;
}