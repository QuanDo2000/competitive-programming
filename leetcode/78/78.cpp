#include <bits/stdc++.h>
using namespace std;

// Solution
class Solution {
   public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> cur;
        dfs(nums, 0, cur, ans);
        return ans;
    }

   private:
    void dfs(vector<int>& nums, int i, vector<int>& cur, vector<vector<int>>& ans) {
        if (i == nums.size()) {
            ans.push_back(cur);
            return;
        }
        dfs(nums, i + 1, cur, ans);
        cur.push_back(nums[i]);
        dfs(nums, i + 1, cur, ans);
        cur.pop_back();
    }
};
