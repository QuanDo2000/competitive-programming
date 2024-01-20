#include <bits/stdc++.h>
using namespace std;

// Solution
class Solution {
   public:
    int calculate(string s) {
        // Calculate with brackets
        stack<int> st;
        int num = 0;
        char sign = '+';
        for (int i = 0; i < s.size(); i++) {
            if (isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
            }
            if (s[i] == '(') {
                int j = i, cnt = 0;
                for (; i < s.size(); i++) {
                    if (s[i] == '(') cnt++;
                    if (s[i] == ')') cnt--;
                    if (cnt == 0) break;
                }
                num = calculate(s.substr(j + 1, i - j - 1));
            }
            if (!isdigit(s[i]) && s[i] != ' ' || i == s.size() - 1) {
                if (sign == '+') {
                    st.push(num);
                } else if (sign == '-') {
                    st.push(-num);
                } else if (sign == '*') {
                    int tmp = st.top();
                    st.pop();
                    st.push(tmp * num);
                } else if (sign == '/') {
                    int tmp = st.top();
                    st.pop();
                    st.push(tmp / num);
                }
                sign = s[i];
                num = 0;
            }
        }
        int res = 0;
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }
        return res;
    }
};
