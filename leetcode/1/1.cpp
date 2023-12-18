#include <bits/stdc++.h>
using namespace std;

// Solution
class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> ans;
    map<int, int> m;

    for (int i = 0; i < nums.size(); i++) {
      int complement = target - nums[i];
      if (m.find(complement) != m.end()) {
        ans.push_back(m[complement]);
        ans.push_back(i);
        return ans;
      }
      m[nums[i]] = i;
    }

    return ans;
  }
};
