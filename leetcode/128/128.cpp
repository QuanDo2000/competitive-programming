#include <bits/stdc++.h>
using namespace std;

// Solution
class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for (int num : nums) s.insert(num);
        int ans = 0;
        for (int num : nums) {
            if (s.find(num - 1) == s.end()) {
                int cur = num;
                int cur_len = 1;
                while (s.find(cur + 1) != s.end()) {
                    cur++;
                    cur_len++;
                }
                ans = max(ans, cur_len);
            }
        }
        return ans;
    }
};
