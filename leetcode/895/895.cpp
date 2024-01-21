#include <bits/stdc++.h>
using namespace std;

// Solution
class FreqStack {
   public:
    FreqStack() {
        max_freq = 0;
    }

    void push(int val) {
        int f = ++freq[val];
        max_freq = max(max_freq, f);
        group[f].push(val);
    }

    int pop() {
        int val = group[max_freq].top();
        group[max_freq].pop();
        if (group[max_freq].empty()) max_freq--;
        freq[val]--;
        return val;
    }

   private:
    unordered_map<int, int> freq;
    unordered_map<int, stack<int>> group;
    int max_freq;
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
