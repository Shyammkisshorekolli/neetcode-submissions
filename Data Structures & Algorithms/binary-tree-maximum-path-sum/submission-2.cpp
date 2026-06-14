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
    int max_length=INT_MIN;
    pair<int,int>solve(TreeNode* root){
        if(!root) return {0,0};
        auto left=solve(root->left);
        auto right=solve(root->right);
        int leftmax=max(left.first,left.second);
        leftmax=max(leftmax,0);
        int rightmax=max(right.first,right.second);
        rightmax=max(rightmax,0);
        int nodeval=root->val;
        max_length=max(leftmax+rightmax+nodeval,max_length);
        max_length=max(max_length,nodeval);
        return {nodeval+leftmax,nodeval+rightmax};
    }
    int maxPathSum(TreeNode* root) {
        solve(root);
        return max_length;
    }
};
