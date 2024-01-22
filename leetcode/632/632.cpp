#include <bits/stdc++.h>
using namespace std;

// Solution
class Solution {
   public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n = nums.size();
        vector<int> idx(n);
        iota(begin(idx), end(idx), 0);
        auto cmp = [&](int i, int j) { return nums[i].front() > nums[j].front(); };
        priority_queue<int, vector<int>, decltype(cmp)> pq(cmp, idx);
        int lo = INT_MAX, hi = INT_MIN;
        for (int i = 0; i < n; i++) {
            lo = min(lo, nums[i].front());
            hi = max(hi, nums[i].front());
        }
        vector<int> res = {lo, hi};
        while (true) {
            int i = pq.top();
            pq.pop();
            nums[i].erase(begin(nums[i]));
            if (nums[i].empty()) break;
            pq.push(i);
            lo = nums[pq.top()].front();
            hi = max(hi, nums[i].front());
            if (hi - lo < res[1] - res[0]) {
                res = {lo, hi};
            }
        }
        return res;
    }
};
