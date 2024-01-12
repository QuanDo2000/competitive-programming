#include <bits/stdc++.h>
using namespace std;

// Solution
class Solution {
   public:
    string decodeString(string s) {
        stack<int> num;
        stack<string> str;
        string ans = "";
        int n = s.size();
        int i = 0;
        while (i < n) {
            if (isdigit(s[i])) {
                int cnt = 0;
                while (isdigit(s[i])) {
                    cnt = cnt * 10 + (s[i] - '0');
                    i++;
                }
                num.push(cnt);
            } else if (s[i] == '[') {
                str.push(ans);
                ans = "";
                i++;
            } else if (s[i] == ']') {
                string tmp = str.top();
                str.pop();
                int cnt = num.top();
                num.pop();
                for (int j = 0; j < cnt; j++) {
                    tmp += ans;
                }
                ans = tmp;
                i++;
            } else {
                ans += s[i];
                i++;
            }
        }
        return ans;
    }
};
