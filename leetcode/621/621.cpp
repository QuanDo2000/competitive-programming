#include <bits/stdc++.h>
using namespace std;

// Solution
class Solution {
   public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> cnt(26, 0);
        for (char c : tasks) cnt[c - 'A']++;
        sort(cnt.begin(), cnt.end());
        int maxCnt = cnt[25] - 1, idleSlots = maxCnt * n;
        for (int i = 24; i >= 0 && cnt[i] > 0; i--) {
            idleSlots -= min(maxCnt, cnt[i]);
        }
        return idleSlots > 0 ? idleSlots + tasks.size() : tasks.size();
    }
};
