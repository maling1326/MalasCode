#include <iostream>
#include <iomanip>
#include "../etc/debug.h"

#include <vector>
using std::vector;

// #include <string>
// using std::string;

// ANSI color codes for colored terminal output
#define CYAN    "\033[36m"
#define GREEN   "\033[32m"
#define RESET   "\033[0m"

// Macros for resetting color and printing new line
#define RESETL  std::cout << "\033[0m";
#define NewLine std::cout << "\n";

vector<int> StringToVectorInt(std::string text); 
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double solution;
        // Hitung posisi tengah gabungan kedua array
        int half  = (nums1.size() + nums2.size()) / 2 + 1,
            max   = nums1.size() + nums2.size(),       // Total elemen gabungan
            maxi1 = nums1.size() - 1,                   // Indeks terakhir nums1
            maxi2 = nums2.size() - 1,                   // Indeks terakhir nums2
            i1    = 0,                                  // Pointer untuk nums1
            i2    = 0;                                  // Pointer untuk nums2

        // Lakukan merge sampai posisi tengah gabungan
        for (int i = 0; i < half; i++) {
            bool canTakeFromNums1 = (i1 <= maxi1);     // Apakah masih ada elemen di nums1
            bool canTakeFromNums2 = (i2 <= maxi2);     // Apakah masih ada elemen di nums2

            // Ambil elemen terkecil dari nums1 atau nums2 jika masih ada
            if (canTakeFromNums1 && (!canTakeFromNums2 || nums1[i1] <= nums2[i2])) {
                nums1.push_back(nums1[i1]);             // Tambahkan elemen nums1 ke akhir nums1
                i1++;                                  // Geser pointer nums1
            } else if (canTakeFromNums2) {
                nums1.push_back(nums2[i2]);             // Tambahkan elemen nums2 ke akhir nums1
                i2++;                                  // Geser pointer nums2
            }
        }

        // Hitung median berdasarkan total elemen ganjil/genap
        if (max % 2 == 0) {
            // Jika genap, rata-rata dua elemen tengah terakhir
            solution = ((double)nums1[nums1.size() - 1] + (double)nums1[nums1.size() - 2]) / 2;
        } else {
            // Jika ganjil, elemen tengah terakhir
            solution = (double)nums1[nums1.size() - 1];
        }
        return solution;
    }
};


int main() {
    Solution solution;
    std::string Text1, Text2;
    
    std::cout << "Masukkan Vector integer dengan dipisahkan oleh " << GREEN << "','" << RESET << "\n Vector Pertama -> " << CYAN;
    std::cin  >> Text1; RESETL
    std::cout << " Vector Kedua   -> " << CYAN;
    std::cin  >> Text2; RESETL
    
    vector<int> nums1 = StringToVectorInt(Text1);
    vector<int> nums2 = StringToVectorInt(Text2);
    
    double answer = solution.findMedianSortedArrays(nums1, nums2);
    NewLine
    
    std::cout << "Median dari kombinasi kedua vektor adalah " << GREEN << std::fixed << std::setprecision(4) << answer << RESET << "."; NewLine
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
