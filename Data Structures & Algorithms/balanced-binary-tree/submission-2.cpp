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
    bool found=true;
    int height(TreeNode* node){
        if(node==nullptr) return 0;
        int x=height(node->left);
        int y=height(node->right);
        if(abs(x-y)>1) found=false;
        return 1+max(x,y);
    }
    bool isBalanced(TreeNode* root) {
        height(root);
        return found;
    }
};
