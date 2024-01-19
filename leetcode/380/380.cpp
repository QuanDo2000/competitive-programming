#include <bits/stdc++.h>
using namespace std;

// Solution
class RandomizedSet {
   public:
    RandomizedSet() {}

    bool insert(int val) {
        if (search(val)) return false;

        vals.push_back(val);
        valToIndex[val] = vals.size() - 1;
        return true;
    }

    bool remove(int val) {
        if (!search(val)) return false;

        int index = valToIndex[val];
        valToIndex[vals.back()] = index;
        swap(vals[index], vals.back());
        vals.pop_back();
        valToIndex.erase(val);
        return true;
    }

    int getRandom() {
        return vals[rand() % vals.size()];
    }

   private:
    unordered_map<int, int> valToIndex;
    vector<int> vals;

    bool search(int val) {
        return valToIndex.find(val) != valToIndex.end();
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
