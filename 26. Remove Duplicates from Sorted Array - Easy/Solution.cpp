#include <iostream>
#include <vector>
using std::vector;

// ANSI color codes for colored terminal output
#define CYAN    "\033[36m"
#define GREEN   "\033[32m"
#define RESET   "\033[0m"

// Macros for resetting color and printing new line
#define RESETL  std::cout << "\033[0m";
#define NewLine std::cout << "\n";

// Fungsi untuk melakukan partisi pada vector
int partition(vector<int>& vec, int left, int right) {
    int pivot = vec[right];  // pivot diambil dari elemen paling kanan
    int i = left - 1;        // indeks elemen yang lebih kecil dari pivot

    for (int j = left; j < right; j++) {
        if (vec[j] <= pivot) {
            i++;
            std::swap(vec[i], vec[j]);
        }
    }
    std::swap(vec[i + 1], vec[right]);
    return i + 1;  // posisi pivot setelah partisi
}

// Fungsi Quick Sort utama
void quickSort(vector<int>& vec, int left, int right) {
    if (left < right) {
        int pivotIndex = partition(vec, left, right);
        quickSort(vec, left, pivotIndex - 1);   // urutkan bagian kiri pivot
        quickSort(vec, pivotIndex + 1, right);  // urutkan bagian kanan pivot
    }
}

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int unique{1};
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i - 1] == nums[i])
                continue;

            unique++;
            nums[unique - 1] = nums[i];
        }
        nums.erase(nums.begin() + unique, nums.end());
        return unique;
    }
};

int main() {
    Solution solution;
    vector<int> nums;
    std::string temp, tempNum;

    std::cout << "Input numbers, separated by ','\n -> " << CYAN;
    std::cin  >> temp; RESETL

    for (int i = 0; i < temp.size(); i++) {
        if (temp[i] == ',') {
            nums.push_back(std::stoi(tempNum));
            tempNum.clear();
        }
        else if (temp[i] == ' ')
            continue;
        else 
            tempNum.push_back(temp[i]);
    }
    nums.push_back(std::stoi(tempNum));

    quickSort(nums, 0, nums.size()-1);
    NewLine
    int k = solution.removeDuplicates(nums);

    //print all
    std::cout << "Unique = " << GREEN << k << RESET;
    NewLine
    std::cout << "Nums   = [ ";
    for (int i = 0; i < nums.size() - 1; i++)
        std::cout << GREEN << nums[i] << RESET << ", ";
    std::cout << GREEN << nums[nums.size() - 1] << RESET << " ]";

    NewLine NewLine
    
    return 0;
}