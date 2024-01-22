#include <bits/stdc++.h>
using namespace std;

// Solution
class Solution {
   public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> res;
        unordered_map<string, int> m;
        set<int> s;
        for (int i = 0; i < words.size(); i++) {
            m[words[i]] = i;
            s.insert(words[i].size());
        }
        for (int i = 0; i < words.size(); i++) {
            string word = words[i];
            reverse(word.begin(), word.end());
            if (m.count(word) && m[word] != i) res.push_back({i, m[word]});
            int len = word.size();
            for (int j : s) {
                if (j >= len) continue;
                if (isPalindrome(word, 0, len - j - 1) && m.count(word.substr(len - j))) res.push_back({i, m[word.substr(len - j)]});
                if (isPalindrome(word, j, len - 1) && m.count(word.substr(0, j))) res.push_back({m[word.substr(0, j)], i});
            }
        }
        return res;
    }

   private:
    bool isPalindrome(string s, int i = 0, int j = -1) {
        if (j == -1) j = s.size() - 1;
        while (i < j) {
            if (s[i++] != s[j--]) return false;
        }
        return true;
    }
};
