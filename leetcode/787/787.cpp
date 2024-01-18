#include <bits/stdc++.h>
using namespace std;

// Solution
class Solution {
   public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        const int INF = 1e9;
        vector<vector<int>> dp(k + 2, vector<int>(n, INF));
        dp[0][src] = 0;
        for (int i = 1; i <= k + 1; i++) {
            dp[i][src] = 0;
            for (auto& flight : flights) {
                int u = flight[0], v = flight[1], w = flight[2];
                dp[i][v] = min(dp[i][v], dp[i - 1][u] + w);
            }
        }
        return dp[k + 1][dst] == INF ? -1 : dp[k + 1][dst];
    }
};
