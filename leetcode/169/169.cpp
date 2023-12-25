#include <bits/stdc++.h>
using namespace std;

// Solution
class Solution {
   public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0, ans = 0;
        for (int num : nums) {
            if (cnt == 0) {
                ans = num;
            }

            if (num == ans)
                cnt++;
            else
                cnt--;
        }
        return ans;
    }
};
