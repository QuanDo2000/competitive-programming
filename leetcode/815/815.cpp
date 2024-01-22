#include <bits/stdc++.h>
using namespace std;

// Solution
class Solution {
   public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) return 0;
        unordered_map<int, vector<int>> stopToBus;
        for (int i = 0; i < routes.size(); i++) {
            for (auto stop : routes[i]) {
                stopToBus[stop].push_back(i);
            }
        }
        queue<int> q;
        unordered_set<int> visited;
        for (auto bus : stopToBus[source]) {
            q.push(bus);
            visited.insert(bus);
        }
        int res = 1;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int bus = q.front();
                q.pop();
                for (auto stop : routes[bus]) {
                    if (stop == target) return res;
                    for (auto nextBus : stopToBus[stop]) {
                        if (visited.count(nextBus)) continue;
                        q.push(nextBus);
                        visited.insert(nextBus);
                    }
                }
            }
            res++;
        }
        return -1;
    }
};
