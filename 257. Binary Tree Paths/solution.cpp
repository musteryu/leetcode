/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if (root == nullptr) return vector<string>();
        string vs = to_string(root->val);
        if (!root->left && !root->right) return vector<string> { vs };
        vector<string> res;
        if (root->left) {
            for (auto &s: binaryTreePaths(root->left)) {
                res.push_back(vs + "->" + s);
            }
        }
        if (root->right) {
            for (auto &s: binaryTreePaths(root->right)) {
                res.push_back(vs + "->" + s);
            }
        }
        return res;
    }
};
