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
    int maxPathSum(TreeNode *root) {
        int ans = INT_MIN;
        maxPathSum(root, ans);
        return ans;
    }

   private:
    int maxPathSum(TreeNode *root, int &ans) {
        if (!root) return 0;
        int left = max(0, maxPathSum(root->left, ans));
        int right = max(0, maxPathSum(root->right, ans));
        ans = max(ans, root->val + left + right);
        return root->val + max(left, right);
    }
};
