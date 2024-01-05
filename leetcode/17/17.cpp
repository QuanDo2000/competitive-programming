#include <bits/stdc++.h>
using namespace std;

// Solution
class Solution {
   public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        vector<string> ans;
        string cur;
        dfs(digits, 0, cur, ans);
        return ans;
    }

   private:
    void dfs(string &digits, int i, string &cur, vector<string> &ans) {
        if (i == digits.size()) {
            ans.push_back(cur);
            return;
        }
        for (char c : m[digits[i] - '0']) {
            cur.push_back(c);
            dfs(digits, i + 1, cur, ans);
            cur.pop_back();
        }
    }

    vector<string> m = {"", "", "abc", "def", "ghi",
                        "jkl", "mno", "pqrs", "tuv", "wxyz"};
};
