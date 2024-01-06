#include <bits/stdc++.h>
using namespace std;

// Solution
class Solution {
   public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> ans;
        if (n == 1) {
            ans.push_back(0);
            return ans;
        }
        vector<int> degree(n, 0);
        vector<vector<int>> adj(n);
        for (auto& edge : edges) {
            degree[edge[0]]++;
            degree[edge[1]]++;
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (degree[i] == 1) q.push(i);
        }
        while (!q.empty()) {
            int size = q.size();
            ans.clear();
            for (int i = 0; i < size; i++) {
                int u = q.front();
                q.pop();
                ans.push_back(u);
                for (int v : adj[u]) {
                    degree[v]--;
                    if (degree[v] == 1) q.push(v);
                }
            }
        }
        return ans;
    }
};
