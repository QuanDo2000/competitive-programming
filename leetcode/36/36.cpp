#include <bits/stdc++.h>
using namespace std;

// Solution
class Solution {
   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        vector<vector<bool>> row(n, vector<bool>(n, false));
        vector<vector<bool>> col(n, vector<bool>(n, false));
        vector<vector<bool>> box(n, vector<bool>(n, false));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '1';
                    int k = (i / 3) * 3 + (j / 3);
                    if (row[i][num] || col[j][num] || box[k][num]) return false;
                    row[i][num] = col[j][num] = box[k][num] = true;
                }
            }
        }
        return true;
    }
};
