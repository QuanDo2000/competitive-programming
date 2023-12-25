#include <bits/stdc++.h>
using namespace std;

// Solution
class MyQueue {
   public:
    MyQueue() {
    }

    void push(int x) {
        moveToS1();
        s1.push(x);
        moveToS2();
    }

    int pop() {
        int res = peek();
        s2.pop();
        return res;
    }

    int peek() {
        return s2.top();
    }

    bool empty() {
        return s1.empty() && s2.empty();
    }

   private:
    stack<int> s1, s2;

    void moveToS2() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
    }

    void moveToS1() {
        if (s1.empty()) {
            while (!s2.empty()) {
                s1.push(s2.top());
                s2.pop();
            }
        }
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
