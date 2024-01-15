#include <bits/stdc++.h>
using namespace std;

// Solution
class Solution {
   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size(), l = 0, r = n * m - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (matrix[mid / m][mid % m] == target) return true;
            if (matrix[mid / m][mid % m] < target)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return false;
    }
};
