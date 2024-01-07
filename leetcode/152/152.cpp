#include <bits/stdc++.h>
using namespace std;

// Solution
class Solution {
   public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int ans = nums[0];
        int maxP = nums[0];
        int minP = nums[0];
        for (int i = 1; i < n; i++) {
            int tmp = maxP;
            maxP = max(max(maxP * nums[i], minP * nums[i]), nums[i]);
            minP = min(min(tmp * nums[i], minP * nums[i]), nums[i]);
            ans = max(ans, maxP);
        }
        return ans;
    }
};
