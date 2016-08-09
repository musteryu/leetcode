#include <vector>
using std::vector;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};
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
    vector<int> rightSideView(TreeNode* root) {
        vector<TreeNode *> currLevel;
        vector<int> res;
        if (root != NULL) currLevel.push_back(root);
        int idx = 0, currLen = 0;
        while (idx != currLevel.size()) {
            res.push_back(currLevel.back()->val);
            currLen = currLevel.size();
            for (idx; idx < currLen; idx++) {
                if (currLevel[idx]->left != NULL)
                    currLevel.push_back(currLevel[idx]->left);
                if (currLevel[idx]->right != NULL)
                    currLevel.push_back(currLevel[idx]->right);
            }
        }
        return res;
    }
};

class Solution {
public:
    void solve(TreeNode *root, int level, vector &res) {
        if (root == NULL) return;
        if (res.size() < level) res.push_back(root->val);
        solve(root->right, level+1, res);
        solve(root->left, level+1, res);
    }

    vector<int> rightSideView(TreeNode *root) {
        vector<int> res;
        solve(root, 1, res);
        return res;
    }
}