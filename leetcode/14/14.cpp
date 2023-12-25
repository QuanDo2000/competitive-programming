#include <bits/stdc++.h>
using namespace std;

// Solution
class Solution {
   public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        int n = strs.size();
        int m = strs[0].size();
        for (int j = 0; j < m; ++j) {
            for (int i = 1; i < n; ++i) {
                if (j == strs[i].size() || strs[i][j] != strs[0][j]) {
                    return strs[0].substr(0, j);
                }
            }
        }
        return strs[0];
    }
};
