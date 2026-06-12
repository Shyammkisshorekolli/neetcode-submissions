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
    TreeNode* solve(TreeNode *node){
        if(node==nullptr) return nullptr;
        solve(node->left);
        solve(node->right);
        TreeNode *currleft=node->left;
        TreeNode *currright=node->right;
        node->left=currright;
        node->right=currleft;
        return node;
    }
    TreeNode* invertTree(TreeNode* root) {
        return solve(root);
    }
};
