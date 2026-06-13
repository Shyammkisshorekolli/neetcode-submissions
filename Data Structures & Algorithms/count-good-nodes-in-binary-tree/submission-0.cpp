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
    int count=0;
    void solve(TreeNode* root,int x){
        if(root==nullptr) return;
        if(root->val>max(root->val,x)||root->val==max(root->val,x)) count++;
        x=max(root->val,x);
        solve(root->left,x);
        solve(root->right,x);
        return;
    }
    int goodNodes(TreeNode* root) {
        solve(root,root->val);
        return count;
    }
};
