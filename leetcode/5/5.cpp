#include <bits/stdc++.h>
using namespace std;

// Solution
class Solution {
   public:
    string longestPalindrome(string s) {
        int n = s.size();
        int dp[n][n];
        memset(dp, 0, sizeof(dp));
        int max_len = 1;
        int start = 0;
        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;
            if (i < n - 1 && s[i] == s[i + 1]) {
                dp[i][i + 1] = 1;
                max_len = 2;
                start = i;
            }
        }
        for (int len = 3; len <= n; len++) {
            for (int i = 0; i < n - len + 1; i++) {
                int j = i + len - 1;
                if (dp[i + 1][j - 1] && s[i] == s[j]) {
                    dp[i][j] = 1;
                    max_len = len;
                    start = i;
                }
            }
        }
        return s.substr(start, max_len);
    }
};
