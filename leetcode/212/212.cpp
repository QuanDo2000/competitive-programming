#include <bits/stdc++.h>
using namespace std;

// Solution
class Solution {
   public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for (auto word : words) {
            string s = "";
            for (auto c : word) {
                if (!trie.count(s)) trie[s] = 0;
                s.push_back(c);
            }
            dict.insert(word);
        }
        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[0].size(); j++) {
                rec(board, i, j, 0);
            }
        vector<string> res;
        for (auto word : ans) res.push_back(word);
        return res;
    }

   private:
    string word;
    bool visited[12][12];
    unordered_set<string> ans;
    unordered_set<string> dict;
    unordered_map<string, int> trie;

    void rec(vector<vector<char>>& board, int i, int j, int k) {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || visited[i][j]) return;
        word.push_back(board[i][j]);
        if (dict.count(word)) ans.insert(word);
        if (trie.count(word)) {
            visited[i][j] = true;
            rec(board, i + 1, j, k + 1);
            rec(board, i - 1, j, k + 1);
            rec(board, i, j + 1, k + 1);
            rec(board, i, j - 1, k + 1);
            visited[i][j] = false;
        }
        word.pop_back();
    }
};
