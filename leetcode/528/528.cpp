#include <bits/stdc++.h>
using namespace std;

// Solution
class Solution {
   public:
    Solution(vector<int>& w) {
        for (int ind : w) {
            s.push_back(s.empty() ? ind : s.back() + ind);
        }
    }

    int pickIndex() {
        int m = s.back();
        int r = rand() % m;

        auto it = upper_bound(s.begin(), s.end(), r);
        return it - s.begin();
    }

   private:
    vector<int> s;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
