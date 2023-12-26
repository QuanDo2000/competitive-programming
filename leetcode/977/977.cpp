#include <bits/stdc++.h>
using namespace std;

// Solution
class Solution {
   public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int pos = 0;
        while (pos < n && nums[pos] < 0) pos++;
        int neg = pos - 1;
        vector<int> ans;
        while (neg >= 0 && pos < n) {
            if (nums[neg] * nums[neg] < nums[pos] * nums[pos]) {
                ans.push_back(nums[neg] * nums[neg]);
                neg--;
            } else {
                ans.push_back(nums[pos] * nums[pos]);
                pos++;
            }
        }
        while (neg >= 0) {
            ans.push_back(nums[neg] * nums[neg]);
            neg--;
        }
        while (pos < n) {
            ans.push_back(nums[pos] * nums[pos]);
            pos++;
        }
        return ans;
    }
};
