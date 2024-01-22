#include <bits/stdc++.h>
using namespace std;

// Solution
class Solution {
   public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        int ans = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                ans = max(ans, dfs(matrix, dp, i, j));
            }
        return ans;
    }

   private:
    int dfs(vector<vector<int>>& matrix, vector<vector<int>>& dp, int i, int j) {
        if (dp[i][j] != -1) return dp[i][j];
        int m = matrix.size(), n = matrix[0].size();
        int ans = 1;
        vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for (auto [dx, dy] : dirs) {
            int x = i + dx, y = j + dy;
            if (x < 0 || x >= m || y < 0 || y >= n || matrix[x][y] <= matrix[i][j]) continue;
            ans = max(ans, 1 + dfs(matrix, dp, x, y));
        }
        return dp[i][j] = ans;
    }
};
