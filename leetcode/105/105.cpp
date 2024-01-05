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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return buildTree(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }

   private:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder, int preStart, int preEnd, int inStart, int inEnd) {
        if (preStart > preEnd) return nullptr;
        TreeNode *root = new TreeNode(preorder[preStart]);
        int rootIndex = inStart;
        while (inorder[rootIndex] != preorder[preStart]) rootIndex++;
        int leftSize = rootIndex - inStart;
        root->left = buildTree(preorder, inorder, preStart + 1, preStart + leftSize, inStart, rootIndex - 1);
        root->right = buildTree(preorder, inorder, preStart + leftSize + 1, preEnd, rootIndex + 1, inEnd);
        return root;
    }
};
