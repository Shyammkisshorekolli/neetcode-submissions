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
    int solve(TreeNode* node,int n){
        if(node==nullptr) return n;
        n++;
        int x=solve(node->left,n);
        int y=solve(node->right,n);
        return max(x,y);
    }
    int maxDepth(TreeNode* root) {
        return solve(root,0);
    }
};
