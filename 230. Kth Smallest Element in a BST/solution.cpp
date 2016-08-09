/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        return helper(root, k);
    }
private:
    int helper(TreeNode* root, int& k) {
        if (root) {
            int x = helper(root->left, k);
            return !k ? x : !--k ? root->val : helper(root->right, k);
        }
    }
};