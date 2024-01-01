#include <bits/stdc++.h>
using namespace std;

// Solution
class Solution {
   public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, string> emailToName;
        unordered_map<string, vector<string>> graph;
        unordered_set<string> visited;
        vector<vector<string>> res;

        for (auto& account : accounts) {
            string name = account[0];
            visited.insert(name);
            for (int i = 1; i < account.size(); i++) {
                emailToName[account[i]] = name;
                graph[account[i]].push_back(account[i - 1]);
                graph[account[i - 1]].push_back(account[i]);
            }
        }

        for (auto& [email, name] : emailToName) {
            if (visited.find(email) == visited.end()) {
                vector<string> emails;
                dfs(graph, email, visited, emails);
                sort(emails.begin(), emails.end());
                emails.insert(emails.begin(), name);
                res.push_back(emails);
            }
        }

        return res;
    }

   private:
    void dfs(unordered_map<string, vector<string>>& graph, string email,
             unordered_set<string>& visited, vector<string>& emails) {
        visited.insert(email);
        emails.push_back(email);
        for (auto& neighbor : graph[email]) {
            if (visited.find(neighbor) == visited.end())
                dfs(graph, neighbor, visited, emails);
        }
    }
};
