#include <bits/stdc++.h>
using namespace std;

// Solution
class Solution {
   public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans, cur(26, 0), cnt(26, 0);
        for (char c : p) cnt[c - 'a']++;
        for (int i = 0; i < s.size(); i++) {
            cur[s[i] - 'a']++;
            if (i >= p.size()) cur[s[i - p.size()] - 'a']--;
            if (cur == cnt) ans.push_back(i - p.size() + 1);
        }
        return ans;
    }
};
