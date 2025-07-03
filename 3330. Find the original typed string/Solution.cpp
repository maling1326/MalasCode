#include <iostream>
#define string std::string

class Solution {
public:
    int possibleStringCount(string word) 
    {
        int n = word.size();
        if (n == 0) return 0;
        
        int result = 1;
        char behind = '\0';
        for (char c : word) 
        {
            if (c == behind)
                result++;
            behind = c;
        }

        return result;
    }
};

/*
#########################         TEST CASE        #########################
1. Input: "aabbcccc"    -> Output: 6
2. Input: "abc"         -> Output: 1
3. Input: "aaaa"        -> Output: 4
4. Input: "aba"         -> Output: 1
5. Input: "abaa"        -> Output: 2

# TEST CASE 1
aabbcccc
aa, bb, cccc
01, 01, 0123
-> Result += Multiple_Char[0] + Multiple_Char[1] + Multiple_Char[2]
-> Result += 1 + 1 + 3
-> Result += 5
-> Result = 1 + 5
-> Result = 6
# Test possible string
1. aabbcccc (1, 1, 3)
2. aabbccc  (1, 1, 2)
3. aabbcc   (1, 1, 1)
4. aabbc    (1, 1, 0)
5. aabcccc  (1, 0, 3)
6. abbcccc  (0, 1, 3)

# TEST CASE 2
abc
a, b, c
0, 0, 0
-> Result += Multiple_Char[0] + Multiple_Char[1] + Multiple_Char[2]
-> Result += 0 + 0 + 0
-> Result += 0
-> Result = 1 + 0
-> Result = 1
# Test possible string
1. abc (0, 0, 0)

# TEST CASE 3
aaaa
aaaa
0123
-> Result += Multiple_Char[0]
-> Result += 3
-> Result = 1 + 3
-> Result = 4
# Test possible string
1. aaaa (3)
2. aaa  (2)
3. aa   (1)
4. a    (0)

# TEST CASE 4
aba
a, b, a
0, 0, 0
-> Result += Multiple_Char(1) + Multiple_Char(2) + Multiple_Char(3)
-> Result += 0 + 0 + 0
-> Result += 0
-> Result = 1 + 0
-> Result = 1
# Test possible string
1. aba (0, 0, 0)

# TEST CASE 5
abaa
a, b, aa
0, 0, 01
-> Result += Multiple_Char(1) + Multiple_Char(2) + Multiple_Char(3)
-> Result += 0 + 0 + 1
-> Result += 1
-> Result = 1 + 1
-> Result = 2
# Test possible string
1. abaa (0, 0, 1)
2. aba  z(0, 0, 0)

#########################         TEST CASE        #########################

######################### Sended to LeetCode 1 & 2 #########################

Sended to LeetCode # 1 & 2:
NOTES :
ERROR, because its counting number from its own ASCII value, not from order of the string

CONSIDERATIONS:
if string has only 1 unique character then return size of string
if string is <= 2 then return 1 because it can be only 1 possible string
if perlettercount is 1 then return size of string
if perlettercount is > 1 then +1 to result

CONCLUSION:
result started from 1
we do need to count the number of unique characters

CODES:
class Solution {
public:
    int possibleStringCount(string word) 
    {
        int n = word.size();
        if (n == 0) return 0;
        
        // The result is the number of unique characters
        int result = 1;

        // Count the number of unique characters
        int uniqueCount = 0;
        string temp;
        int perLetterCount[256] = {0}; // Assuming ASCII characters
        bool seen[256] = {false}; // To track unique characters
        for (char c : word) {
            if (!seen[c]) {
                seen[c] = true;
                uniqueCount++;
                temp += c; // Store unique characters
            }
            perLetterCount[c]++;
        }

        // If all characters are the same, return the size of the string
        if (uniqueCount == 1) 
            return n;
        
        else if (n <= 2) {
            return 1; // If the string is of length 1 or 2, return its size
        }

        // Calculate the result based on the unique character counts
        for (char i : temp)
            result += (perLetterCount[i] - 1); // Add the count of each unique character minus one

        return result;
    }
};

######################### Sended to LeetCode 1 & 2 #########################

#########################   Sended to LeetCode 3   #########################

Sended to LeetCode # 3:
NOTES :
APPROVED, we just need result start from 1
and then if the char behind and right now is the same
then we add 1 to the result
thats all

CODES:
CODES:
class Solution {
public:
    int possibleStringCount(string word) 
    {
        int n = word.size();
        if (n == 0) return 0;
        
        // The result is the number of unique characters
        int result = 1;

        // Count the number of unique characters
        int uniqueCount = 0;
        string temp;
        int perLetterCount[256] = {0}; // Assuming ASCII characters
        bool seen[256] = {false}; // To track unique characters
        for (char c : word) {
            if (!seen[c]) {
                seen[c] = true;
                uniqueCount++;
                temp += c; // Store unique characters
            }
            perLetterCount[c]++;
        }

        // If all characters are the same, return the size of the string
        if (uniqueCount == 1) 
            return n;
        
        else if (n <= 2) {
            return 1; // If the string is of length 1 or 2, return its size
        }

        // Calculate the result based on the unique character counts
        for (char i : temp)
            result += (perLetterCount[i] - 1); // Add the count of each unique character minus one

        return result;
    }
};

#########################   Sended to LeetCode 3   #########################
*/

int main() {
    Solution solution;
    string word;

    // input
    std::cout << "Enter a string: ";
    std::cin >> word;

    int result = solution.possibleStringCount(word);
    std::cout << "Possible string count for '" << word << "': " << result << std::endl;
    return 0;
}