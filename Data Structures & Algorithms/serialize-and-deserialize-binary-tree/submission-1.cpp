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

class Codec {
public:

    void serializeHelper(TreeNode* root, string& s) {
        if (!root) {
            s += "#,";
            return;
        }

        s += to_string(root->val) + ",";

        serializeHelper(root->left, s);
        serializeHelper(root->right, s);
    }

    string serialize(TreeNode* root) {
        string s;
        serializeHelper(root, s);
        return s;
    }

    TreeNode* build(vector<string>& nodes, int& idx) {
        if (nodes[idx] == "#") {
            idx++;
            return nullptr;
        }

        TreeNode* root = new TreeNode(stoi(nodes[idx++]));

        root->left = build(nodes, idx);
        root->right = build(nodes, idx);

        return root;
    }

    TreeNode* deserialize(string data) {

        vector<string> nodes;
        string curr;

        for (char c : data) {
            if (c == ',') {
                nodes.push_back(curr);
                curr.clear();
            } else {
                curr += c;
            }
        }

        int idx = 0;
        return build(nodes, idx);
    }
};
