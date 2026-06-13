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
    bool valid = true;

    pair<long long,long long> solve(TreeNode* root){
        if(!root)
            return {LLONG_MAX, LLONG_MIN};

        auto left = solve(root->left);
        auto right = solve(root->right);

        if(left.second >= root->val)
            valid = false;

        if(right.first <= root->val)
            valid = false;

        long long mn = min((long long)root->val,
                           min(left.first, right.first));

        long long mx = max((long long)root->val,
                           max(left.second, right.second));

        return {mn, mx};
    }

    bool isValidBST(TreeNode* root) {
        solve(root);
        return valid;
    }
};