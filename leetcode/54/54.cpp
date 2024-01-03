#include <bits/stdc++.h>
using namespace std;

// Solution
class Solution {
   public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int n = matrix.size();
        if (n == 0) return ans;
        int m = matrix[0].size();
        int i = 0, j = 0;
        int di = 0, dj = 1;
        int cnt = 0;
        while (cnt < n * m) {
            ans.push_back(matrix[i][j]);
            matrix[i][j] = INT_MIN;
            cnt++;
            if (i + di < 0 || i + di >= n || j + dj < 0 || j + dj >= m || matrix[i + di][j + dj] == INT_MIN) {
                int tmp = di;
                di = dj;
                dj = -tmp;
            }
            i += di;
            j += dj;
        }
        return ans;
    }
};
