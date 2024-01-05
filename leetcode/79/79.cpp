#include <bits/stdc++.h>
using namespace std;

// Solution
class Solution {
   public:
    bool exist(vector<vector<char>> &board, string word) {
        if (board.empty()) return false;
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n));
        bool ans = false;
        for (int i = 0; i < m && !ans; i++)
            for (int j = 0; j < n && !ans; j++)
                dfs(board, word, 0, i, j, visited, ans);
        return ans;
    }

   private:
    void dfs(vector<vector<char>> &board, string &word, int i, int r, int c, vector<vector<bool>> &visited, bool &ans) {
        if (i == word.size()) {
            ans = true;
            return;
        }
        if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size() || visited[r][c] || board[r][c] != word[i]) return;
        visited[r][c] = true;
        dfs(board, word, i + 1, r - 1, c, visited, ans);
        dfs(board, word, i + 1, r + 1, c, visited, ans);
        dfs(board, word, i + 1, r, c - 1, visited, ans);
        dfs(board, word, i + 1, r, c + 1, visited, ans);
        visited[r][c] = false;
    }
};
