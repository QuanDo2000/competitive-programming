#include <bits/stdc++.h>
using namespace std;

// Solution
class Solution {
   public:
    int myAtoi(string s) {
        int i = 0;
        while (i < s.size() && s[i] == ' ') i++;
        if (i == s.size()) return 0;
        int sign = 1;
        if (s[i] == '-') {
            sign = -1;
            i++;
        } else if (s[i] == '+') {
            i++;
        }
        long long ans = 0;
        while (i < s.size() && s[i] >= '0' && s[i] <= '9') {
            ans = ans * 10 + (s[i] - '0');
            if (ans > INT_MAX) {
                if (sign == 1)
                    return INT_MAX;
                else
                    return INT_MIN;
            }
            i++;
        }
        return ans * sign;
    }
};
