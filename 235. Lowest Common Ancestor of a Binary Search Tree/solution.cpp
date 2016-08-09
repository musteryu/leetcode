/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <list>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
private:
    list<TreeNode*> dfs(TreeNode *root, TreeNode *p) {
        list<TreeNode*> path;
        if (root->val == p->val) {
            path.push_back(root);
        } else if (p->val > root->val) {
            path = dfs(root->right, p);
            path.push_back(root);
        } else {
            path = dfs(root->left, p);
            path.push_back(root);
        }
        return path;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        list<TreeNode*> p_path = dfs(root, p);
        list<TreeNode*> q_path = dfs(root, q);
        auto p_iter = p_path.begin();
        auto q_iter = q_path.begin();
        while (*p_iter != *q_iter) {
            if (p_iter == p_path.end()) {
                p_iter = q_path.begin();
            } else p_iter++;
            if (q_iter == q_path.end()) {
                q_iter = p_path.begin();
            } else q_iter++;
        }
        return *p_iter;
    }
};