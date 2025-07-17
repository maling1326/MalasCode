#include <iostream>
using std::string;

// ANSI color codes for colored terminal output
#define CYAN    "\033[36m"
#define GREEN   "\033[32m"
#define RESET   "\033[0m"

// Macros for resetting color and printing new line
#define RESETL  std::cout << "\033[0m";
#define NewLine std::cout << "\n";

class Solution {
public:
    char kthCharacter(int k) {
        string text = "a";            
        int n = 0, max = text.size();

        while (text.size() < k){
            if (n < max) {
                text.push_back((text[n] + 1));
                n++;
                continue;
            }
            n = 0;
            max = text.size();
        }
        
        return text[k - 1];
    }
};

int main() {
    Solution solution;
    int num;
    char ans;

    std::cout << "Input K : " << CYAN;
    std::cin  >> num; RESETL

    if (num > 500)
        num = 500;
    else if (num < 1)
        num = 1;

    std::cout << "Approved : " << GREEN << num << RESET;

    ans = solution.kthCharacter(num);
    NewLine

    std::cout << "Word from K-th : '" << GREEN << ans << RESET << "'";

    NewLine

    return 0;
}