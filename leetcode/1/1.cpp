#include <bits/stdc++.h>
using namespace std;

// Solution
class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;  // unordered_map is faster than map
        int n = nums.size();        // Call size here to avoid calling it in the loop

        for (int i = 0; i < n; i++) {
            int complement = target - nums[i];
            if (m.count(complement)) {
                return {m[complement], i};  // Syntax for returning vector
            }
            m[nums[i]] = i;
        }

        return {};  // Syntax for returning empty vector
    }
};
