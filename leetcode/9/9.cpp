#include <bits/stdc++.h>
using namespace std;

// Solution
class Solution {
   public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        long y = 0, z = x;
        while (z > 0) {
            y = y * 10 + z % 10;
            z /= 10;
        }
        return x == y;
    }
};
