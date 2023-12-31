#include <bits/stdc++.h>
using namespace std;

// Solution
class Solution {
   public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> cur;
        dfs(candidates, target, 0, cur, ans);
        return ans;
    }

   private:
    void dfs(vector<int>& candidates, int target, int i, vector<int>& cur, vector<vector<int>>& ans) {
        if (target == 0) {
            ans.push_back(cur);
            return;
        }
        if (i == candidates.size()) return;
        if (target >= candidates[i]) {
            cur.push_back(candidates[i]);
            dfs(candidates, target - candidates[i], i, cur, ans);
            cur.pop_back();
        }
        dfs(candidates, target, i + 1, cur, ans);
    }
};
