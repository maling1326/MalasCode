#include <iostream>
#include <vector>
#include <unordered_map>

// ANSI color codes for colored terminal output
#define CYAN    "\033[36m"
#define GREEN   "\033[32m"
#define RESET   "\033[0m"

// Macros for resetting color and printing new line
#define RESETL  std::cout << "\033[0m";
#define NewLine std::cout << "\n";

using std::vector;

class Solution {
public:
    // Function to find indices of two numbers that add up to target
    vector<int> twoSum(vector<int>& nums, int target)  {
        std::unordered_map<int, int> map;  // Map to store number and its index
        
        for (int i = 0; i < nums.size(); i++) {
            int search = target - nums[i];  // Complement to find
            
            // Check if complement exists in map
            if (map.find(search) != map.end())
                return {map[search], i};   // Return pair of indices
            
            // Store current number and its index
            map[nums[i]] = i;
        }
        
        return {};  // Return empty vector if no pair found
    }
};

int main() {
    Solution solution;
    vector<int> num;         // Vector to store input numbers
    int target = 0;          // Target sum value
    int muchCount = 0;       // Number of elements to input
    int counting = 1;        // Counter for input prompt display

    // Ask user how many numbers they want to input
    std::cout << "How much num you want? " << CYAN;
    std::cin >> muchCount; 
    RESETL
    NewLine

    // Input loop for the numbers
    while (muchCount > 0)
    {
        int temp;
        
        // Prompt user for each number with colored index
        std::cout << "Num[" << GREEN << counting << RESET << "] : " << CYAN;
        std::cin >> temp; 
        RESETL

        num.push_back(temp);  // Add input number to vector

        counting++;           // Increment prompt counter
        muchCount--;          // Decrement remaining input count
    }

    NewLine

    // Ask user for the target number
    std::cout << "Target Number : " << CYAN;
    std::cin >> target; 
    RESETL

    NewLine

    // Call twoSum to find indices of numbers adding to target
    num = solution.twoSum(num, target);

    // Print the resulting indices in formatted style
    std::cout << "Answer : [" ;

    // Reset muchCount to zero to use as index for printing
    muchCount = 0;

    // Print all but last element with comma separator
    for (int i = num.size(); i > 1; i--)
    {
        std::cout << GREEN << num[muchCount] << RESET << ", ";
        muchCount++;
    }

    // Print last element without trailing comma
    if (!num.empty()) {
        std::cout << GREEN << num[num.size() - 1] << RESET;
    }

    std::cout << "]"; 
    
    return 0;
}
