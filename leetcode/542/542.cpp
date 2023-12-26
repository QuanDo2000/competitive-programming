#include <bits/stdc++.h>
using namespace std;

// Solution
class Solution {
   public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int>> ans(mat.size(), vector<int>(mat[0].size(), INT_MAX));
        queue<pair<int, int>> q;
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[0].size(); j++) {
                if (mat[i][j] == 0) {
                    ans[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        int dx[] = {0, 0, -1, 1};
        int dy[] = {1, -1, 0, 0};

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx < 0 || nx >= mat.size() || ny < 0 || ny >= mat[0].size()) continue;
                if (ans[nx][ny] > ans[x][y] + 1) {
                    ans[nx][ny] = ans[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }

        return ans;
    }
};
