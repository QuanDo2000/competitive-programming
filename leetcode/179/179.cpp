#include <bits/stdc++.h>
using namespace std;

// Solution
class Solution {
   public:
    string largestNumber(vector<int> &nums) {
        vector<string> strs;
        for (int num : nums) strs.push_back(to_string(num));
        sort(strs.begin(), strs.end(), [](string &a, string &b) { return a + b > b + a; });
        string ans;
        for (string &str : strs) ans += str;
        if (ans[0] == '0') return "0";
        return ans;
    }
};
