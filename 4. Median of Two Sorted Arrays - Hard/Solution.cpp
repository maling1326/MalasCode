#include <iostream>

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
        if (nums1.empty()){  
            solution = (nums2.size() % 2 == 0)
                              ? ((double)nums2[nums2.size() / 2 - 1] +
                                 (double)nums2[nums2.size() / 2]) /
                                    2
                              : nums2[nums2.size() / 2];
            return solution;
        }
        if (nums2.empty()) {
            solution = (nums1.size() % 2 == 0)
                              ? ((double)nums1[nums1.size() / 2 - 1] +
                                 (double)nums1[nums1.size() / 2]) /
                                    2
                              : nums1[nums1.size() / 2];
            return solution;
        }
        
        int TotalNum = nums1.size() + nums2.size(),
            maxi1 = nums1.size(), maxi2 = nums2.size(),
            i1 {0}, i2 {0};

        for (int i = 0; i < TotalNum / 2 + 1; i++) {
            if (i1 == maxi1 || (nums1[i1] > nums2[i2] && i2 < maxi2)) {
                nums1.push_back(nums2[i2]);
                i2++;
            } else if (i1 < maxi1 || i2 == maxi2) {
                nums1.push_back(nums1[i1]);
                i1++;
            }
        }
            
        solution = (TotalNum % 2 == 0)
                        ? ((double)nums1[nums1.size() - 1] +
                            (double)nums1[nums1.size() - 2]) /
                            2
                        : nums1[nums1.size() - 1];
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

    /*
    if (10 > nums1.size())
    std::cout << nums1[nums1.size() - 1];
    
    NewLine
    
    for (int n : nums1)
    {
        std::cout << n << " ";
    }
    NewLine
    */    
    
    std::cout << "Median dari kombinasi kedua vektor adalah " << GREEN << answer << RESET << "."; NewLine
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
