#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Solution
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
   public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL)
            return NULL;
        if (root == p || root == q)
            return root;

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        if (left != NULL && left != p && left != q)
            return left;

        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if (right != NULL && right != p && right != q)
            return right;

        if (left != NULL && right != NULL)
            return root;
        else if (left != NULL)
            return left;
        else if (right != NULL)
            return right;
        else
            return NULL;
    }
};
