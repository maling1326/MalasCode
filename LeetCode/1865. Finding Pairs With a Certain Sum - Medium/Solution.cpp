#include <iostream>
#include <chrono>

// #include <iomanip>

#include <vector>
using std::vector;

#include <unordered_map>
using std::unordered_map;

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

void printall(vector<int> v);
void printmap(unordered_map<int, int> m);

class FindSumPairs {
    vector<int> _nums1;
    vector<int> _nums2;
    unordered_map<int, int> freq1;  // Frekuensi kemunculan angka di _nums1
    unordered_map<int, int> freq2;  // Frekuensi kemunculan angka di _nums2

public:
    FindSumPairs(const vector<int>& nums1, const vector<int>& nums2)
        : _nums1(nums1), _nums2(nums2)
    {
        freq1.reserve(nums1.size());  // Reservasi memori untuk efisiensi
        freq2.reserve(nums2.size());

        // Hitung frekuensi setiap angka di nums1
        for (const auto& num : nums1)
            freq1[num]++;

        // Hitung frekuensi setiap angka di nums2
        for (const auto& num : nums2)
            freq2[num]++;
    }

    void add(int index, int val) {
        int oldVal = _nums2[index];
        int newVal = oldVal + val;

        // Kurangi frekuensi nilai lama, hapus jika sudah nol
        freq2[oldVal]--;
        if (freq2[oldVal] == 0)
            freq2.erase(oldVal);

        // Tambah frekuensi nilai baru
        freq2[newVal]++;
        _nums2[index] = newVal;  // Update nilai di vector _nums2
    }

    int count(int tot) {
        int occ = 0;

        // Iterasi pada map yang lebih kecil untuk efisiensi
        if (freq1.size() < freq2.size()) {
            // Untuk setiap angka di freq1, cari pasangan yang melengkapi total
            for (const auto& [num1, count1] : freq1) {
                int complement = tot - num1;
                if (freq2.count(complement))  // Cek apakah pasangan ada di freq2
                    occ += count1 * freq2[complement];  // Hitung semua pasangan
            }
        } else {
            // Jika freq2 lebih kecil, iterasi di freq2 dan cari pasangan di freq1
            for (const auto& [num2, count2] : freq2) {
                int complement = tot - num2;
                if (freq1.count(complement))
                    occ += count2 * freq1[complement];
            }
        }

        return occ;  // Total pasangan yang jumlahnya tot
    }
};

int main() {
    Stopwatch sw;
    int add;
    vector<int> nums1 {1,1,2,2,2,3},
                nums2 {1,4,5,2,5,4};    

    std::cout << "Nums 1 : "; printall(nums1); 
    std::cout << "Nums 2 : "; printall(nums2); 
    // ["FindSumPairs","count","add","count","count","add","add","count"]
    // [[[1,1,2,2,2,3],[1,4,5,2,5,4]],[7],[3,2],[8],[4],[0,1],[1,1],[7]]
    
    NewLine
    sw.start();
    FindSumPairs solution(nums1, nums2);
    
    add = solution.count(7);
    std::cout << "Occure   : " << CYAN << add; RESETL NewLine 
    
    solution.add(3, 2);
    
    add = solution.count(8);
    std::cout << "Occure   : " << CYAN << add; RESETL NewLine 
    
    add = solution.count(4);
    std::cout << "Occure   : " << CYAN << add; RESETL NewLine 
    
    solution.add(0, 1);
    
    solution.add(1,1);
    
    add = solution.count(7);
    std::cout << "Occure   : " << CYAN << add; RESETL NewLine 
    
    sw.stop();
    return 0;
}

void printall(vector<int> v) 
{
    std::cout << "[ ";
    for (int i = 0; i < v.size() - 1; i++)
    {
        std::cout << GREEN << v[i] << RESET << ", ";
    }
    std::cout << GREEN << v[v.size() - 1] << RESET << " ]";
    NewLine
}

void printmap(unordered_map<int, int> m)
{
    for (auto n : m) {
        std::cout << "Key : " << GREEN << n.first << RESET << " || Value : " << CYAN << n.second << RESET; NewLine
    }
}
