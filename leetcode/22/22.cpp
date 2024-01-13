#include <bits/stdc++.h>
using namespace std;

// Solution
class Solution {
   public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s;
        dfs(ans, s, n, n);
        return ans;
    }

   private:
    void dfs(vector<string>& ans, string& s, int l, int r) {
        if (l == 0 && r == 0) {
            ans.push_back(s);
            return;
        }
        if (l > 0) {
            s.push_back('(');
            dfs(ans, s, l - 1, r);
            s.pop_back();
        }
        if (r > l) {
            s.push_back(')');
            dfs(ans, s, l, r - 1);
            s.pop_back();
        }
    }
};
