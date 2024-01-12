#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Solution
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
   public:
    int widthOfBinaryTree(TreeNode *root) {
        if (!root) return 0;
        queue<pair<TreeNode *, unsigned long>> q;
        q.push({root, 0});
        unsigned long ans = 0;
        while (!q.empty()) {
            int n = q.size();
            unsigned long left = q.front().second;
            unsigned long right = left;
            for (int i = 0; i < n; i++) {
                TreeNode *node = q.front().first;
                right = q.front().second;
                q.pop();
                if (node->left) q.push({node->left, 2 * right + 1});
                if (node->right) q.push({node->right, 2 * right + 2});
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};
