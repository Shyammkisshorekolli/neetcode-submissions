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
    int x=0;
    int kthSmallest(TreeNode* root, int k) {
        if(root==nullptr) return x;
        kthSmallest(root->left,k);
        count++;
        if(count==k){
            x=root->val;
            return x;
        }
        kthSmallest(root->right,k);
        return x;
    }
};
