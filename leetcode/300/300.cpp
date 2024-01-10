#include <bits/stdc++.h>
using namespace std;

// Solution
class Solution {
   public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        int ans = 1;
        for (int i = 1; i < nums.size(); i++) {
            int maxLen = 0;
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    maxLen = max(maxLen, dp[j]);
                }
            }
            dp[i] = maxLen + 1;
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
