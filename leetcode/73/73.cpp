#include <bits/stdc++.h>
using namespace std;

// Solution
class Solution {
   public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        bool firstRow = false, firstCol = false;
        for (int i = 0; i < n; i++) {
            if (matrix[i][0] == 0) firstCol = true;
        }
        for (int j = 0; j < m; j++) {
            if (matrix[0][j] == 0) firstRow = true;
        }
        for (int i = 1; i < n; i++) {
            bool zero = false;
            for (int j = 1; j < m; j++) {
                if (matrix[i][j] == 0) {
                    zero = true;
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
            if (zero) matrix[i][0] = 0;
        }
        for (int j = 1; j < m; j++) {
            if (matrix[0][j] == 0) {
                for (int i = 1; i < n; i++) matrix[i][j] = 0;
            }
        }
        for (int i = 1; i < n; i++) {
            if (matrix[i][0] == 0) {
                for (int j = 1; j < m; j++) matrix[i][j] = 0;
            }
        }
        if (firstRow) {
            for (int j = 0; j < m; j++) matrix[0][j] = 0;
        }
        if (firstCol) {
            for (int i = 0; i < n; i++) matrix[i][0] = 0;
        }
    }
};
