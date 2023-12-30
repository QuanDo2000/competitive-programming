#include <bits/stdc++.h>
using namespace std;

// Solution
class Solution {
   public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans += dfs(grid, i, j);
            }
        }
        return ans;
    }

   private:
    int dfs(vector<vector<char>>& grid, int i, int j) {
        int n = grid.size();
        int m = grid[0].size();

        if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == '0') return 0;

        grid[i][j] = '0';
        dfs(grid, i + 1, j);
        dfs(grid, i - 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i, j - 1);

        return 1;
    }
};
