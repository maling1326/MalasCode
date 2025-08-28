#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int> umap;
        umap[numbers[0]] = 0;
        for (int i = 1; i < numbers.size(); ++i) {
            if (auto find = umap.find(target - numbers[i]); find != umap.end())
                 return {find->second + 1, i + 1};
            else umap[numbers[i]] = i;
        }
        return {0, 0};
    }
};

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	Solution s;

	int target;
	//cout << "Target : ";
	cin >> target;

	int n;
	//cout << "Max nums : ";
	cin >> n;
	
	vector<int> nums (n, 0);
	for (int i = 0; i < n; ++i)
		cin >> nums[i];
	
	vector<int> ans = s.twoSum(nums, target);
	
	cout << "[" << ans[0] << "," << ans[1] << "]\n";

	return 0;
}