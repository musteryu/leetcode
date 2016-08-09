/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <cmath>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int countNodes(TreeNode* root) {
        int height = 0;
        TreeNode* iter = root;
        int sum = 0;
        while (iter) {
            iter = iter->left;
            height++;
        }
        int level = height - 2;
        while (root) {
            iter = root->left;
            if (iter == nullptr) {
                sum += 1;
                break;
            }
            for (int i = 0; i < level; i++)
                iter = iter->right;
            if (iter) {
                sum += (1 << (level + 1));
                root = root->right;
            } else {
                sum += (1 << level);
                root = root->left;
            }
            level--;
        }
        return sum;
    }
};