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
    unordered_map<int,int> inmap;
    int preIdx = 0;

    TreeNode* solve(vector<int>& preorder,
                    vector<int>& inorder,
                    int left,
                    int right)
    {
        if(left > right)
            return nullptr;

        int rootVal = preorder[preIdx++];
        TreeNode* root = new TreeNode(rootVal);

        int pos = inmap[rootVal];

        root->left = solve(preorder, inorder, left, pos - 1);
        root->right = solve(preorder, inorder, pos + 1, right);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        for(int i = 0; i < inorder.size(); i++)
            inmap[inorder[i]] = i;

        return solve(preorder, inorder, 0, inorder.size() - 1);
    }
};