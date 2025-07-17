# Two Sums - Leet Code `1`

[My Submission on Leetcode](https://leetcode.com/problems/two-sum/solutions/6910714/two-sums-hash-table-is-quite-easy-actual-c98r)

## Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
Initially, I used two nested for loops to compare each element with every element after it, trying to find two numbers whose sum equals the target. This approach worked but had a time complexity of O(n²) and ran in about 73ms, which is relatively slow for large inputs.

Then, I noticed the problem tags mentioned hash table, which gave me the idea to use a hash table to optimize the search. Instead of comparing each pair explicitly, I could check if the complement of the current number exists in the hash table, enabling faster lookups.

## Approach
<!-- Describe your approach to solving the problem. -->
The approach using a hash table (std::unordered_map) is as follows:

- Iterate through each element nums[i] in the array/vector.

- Calculate the complement value search = target - nums[i].

- Check if search exists in the hash table:
  - If it does, return the indices of the complement and the current element immediately.

- If not found, insert the current number and its index into the hash table for future lookups.

- If no pair is found after completing the iteration, return an empty vector.

This method leverages the average O(1) lookup time of hash tables to reduce the overall time complexity.

## Complexity

- Time complexity:
<!-- Add your time complexity here, e.g. $$O(n)$$ -->
Since each element is processed once and hash table operations (insert and find) take average O(1) time, the total time complexity is O(n), where n is the number of elements in nums.

- Space complexity:
<!-- Add your space complexity here, e.g. $$O(n)$$ -->
The hash table stores up to n elements, so the space complexity is O(n).

## Code

```cpp []
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map; // key: number, value: index

        for (int i = 0; i < nums.size(); i++) {
            int search = target - nums[i];

            // Check if complement exists in map
            if (map.find(search) != map.end()) {
                // Return indices of the two numbers
                return {map[search], i};
            }

            // Insert current number and its index into map
            map[nums[i]] = i;
        }

        // Return empty vector if no pair found
        return {};
    }
};
```
