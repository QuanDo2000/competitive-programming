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
    int pathSum(TreeNode *root, int targetSum) {
        if (root == nullptr) return 0;
        return pathSum(root->left, targetSum) + pathSum(root->right, targetSum) + pathSumFrom(root, targetSum);
    }

    int pathSumFrom(TreeNode *root, long targetSum) {
        if (root == nullptr) return 0;
        int ans = 0;
        if (root->val == targetSum) ans++;
        ans += pathSumFrom(root->left, targetSum - root->val);
        ans += pathSumFrom(root->right, targetSum - root->val);
        return ans;
    }
};
