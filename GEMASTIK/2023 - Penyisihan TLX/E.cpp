#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
	
	int n;
	cin >> n;
	vector<int> nums;
	
	for (int i = 0; i < n; ++i) {
		int t; cin >> t;
		nums.emplace_back(t);
	}
	
	sort(nums.begin(), nums.end());
	nums.erase(unique(nums.begin(), nums.end()), nums.end());
	
	int i = 1, beg = 0;
	string ans = "";
	for (;i < nums.size(); ++i) {
		if (nums[i - 1] == nums[i] - 1) continue;
		
		if (i - beg == 1) ans += to_string(nums[beg]) + ",";
		else 			  ans += to_string(nums[beg]) + "-" + to_string(nums[i - 1]) + ",";
		beg = i;
	}
	if (i - beg == 1) ans += to_string(nums[beg]);
	else 			  ans += to_string(nums[beg]) + "-" + to_string(nums[i - 1]);
	
	cout << ans;
	
	return 0;
}