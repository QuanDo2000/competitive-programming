#include <bits/stdc++.h>
using namespace std;

// Solution
class Solution {
   public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int ans = nums[0];
        int currMax = nums[0];
        for (int i = 1; i < n; i++) {
            currMax = max(nums[i], currMax + nums[i]);
            ans = max(ans, currMax);
        }
        return ans;
    }
};
