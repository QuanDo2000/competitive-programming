#include <bits/stdc++.h>
using namespace std;

// Solution
class TimeMap {
   public:
    TimeMap() {}

    void set(string key, string value, int timestamp) {
        if (m.find(key) == m.end())
            m[key] = vector<pair<int, string>>();
        m[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp) {
        if (m.find(key) == m.end())
            return "";
        vector<pair<int, string>>& v = m[key];
        int l = 0, r = v.size() - 1;
        while (l < r) {
            int mid = (l + r) / 2;
            if (v[mid].first == timestamp)
                return v[mid].second;
            else if (v[mid].first < timestamp)
                l = mid + 1;
            else
                r = mid;
        }
        if (v[l].first <= timestamp)
            return v[l].second;
        else if (l > 0)
            return v[l - 1].second;
        else
            return "";
    }

   private:
    unordered_map<string, vector<pair<int, string>>> m;
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
