#include <bits/stdc++.h>
using namespace std;

// Solution
class Solution {
   public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        int sum = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;

        for (int i = 0; i < n; i++) {
            sum += nums[i];
            ans += mp[sum - k];
            mp[sum]++;
        }

        return ans;
    }
};
