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
    bool solve(TreeNode*p,TreeNode*q){
        if(p==nullptr&&q==nullptr) return true;
        else if(p==nullptr) return false;
        else if(q==nullptr) return false;
        bool x=solve(p->left,q->left);
        bool y=solve(p->right,q->right);
        if(x&&y){
            if(p->val==q->val) return true;
            else return false;
        }
        else return false;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==nullptr) return false;
        if(solve(root,subRoot)) return true;
        return isSubtree(root->left,subRoot)||isSubtree(root->right,subRoot);
    }
};
