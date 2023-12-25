#include <bits/stdc++.h>
using namespace std;

// Solution
class Solution {
   public:
    int longestPalindrome(string s) {
        int odd = 0;
        unordered_map<char, int> m;
        for (char c : s) m[c]++;
        for (auto p : m) {
            if (p.second % 2 == 1) odd++;
        }
        return s.size() - max(0, odd - 1);
    }
};
