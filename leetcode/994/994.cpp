#include <bits/stdc++.h>
using namespace std;

// Solution
class Solution {
   public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;
        int fresh = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        int ans = 0;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int i = q.front().first;
                int j = q.front().second;
                q.pop();

                if (i > 0 && grid[i - 1][j] == 1) {
                    grid[i - 1][j] = 2;
                    fresh--;
                    q.push({i - 1, j});
                }
                if (i < n - 1 && grid[i + 1][j] == 1) {
                    grid[i + 1][j] = 2;
                    fresh--;
                    q.push({i + 1, j});
                }
                if (j > 0 && grid[i][j - 1] == 1) {
                    grid[i][j - 1] = 2;
                    fresh--;
                    q.push({i, j - 1});
                }
                if (j < m - 1 && grid[i][j + 1] == 1) {
                    grid[i][j + 1] = 2;
                    fresh--;
                    q.push({i, j + 1});
                }
            }
            if (!q.empty()) {
                ans++;
            }
        }

        return fresh == 0 ? ans : -1;
    }
};
