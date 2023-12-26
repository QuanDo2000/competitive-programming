#include <bits/stdc++.h>
using namespace std;

// Solution
class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int ans = 0, cur = 0;
        unordered_map<char, int> mp;
        for (int i = 0; i < n; i++) {
            if (mp.find(s[i]) != mp.end()) {
                cur = min(cur + 1, i - mp[s[i]]);
            } else {
                cur++;
            }
            mp[s[i]] = i;
            if (cur > ans) ans = cur;
        }
        return ans;
    }
};
