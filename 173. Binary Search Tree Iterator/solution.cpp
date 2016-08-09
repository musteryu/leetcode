/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
private:
    vector<int> nums;
    int current;
    void dfs(TreeNode *root) {
        if (root == nullptr) return;
        dfs(root->left);
        nums.push_back(root->val);
        dfs(root->right);
    }
public:
    BSTIterator(TreeNode *root): current(0) {
        dfs(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return current < nums.size();
    }

    /** @return the next smallest number */
    int next() {
        return nums[current++];
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */