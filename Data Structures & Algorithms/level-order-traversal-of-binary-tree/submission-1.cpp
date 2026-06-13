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
    int solve_(TreeNode* node,int n){
        if(node==nullptr) return n;
        n++;
        int x=solve_(node->left,n);
        int y=solve_(node->right,n);
        return max(x,y);
    }
    void solve(TreeNode *root,vector<vector<int>>&final,int n){
        if(root==nullptr) return;
        vector<int>ans;
        final[n].push_back(root->val);
        solve(root->left,final,n+1);
        solve(root->right,final,n+1);
        return;
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        int h=solve_(root,0);
        vector<vector<int>>final(h);
        solve(root,final,0);
        return final;
    }
};
