/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
private:
    void do_seri(ostringstream &os, TreeNode *root) {
        if (root) {
            os << to_string(root->val);
            os << " ";
            do_seri(os, root->left);
            do_seri(os, root->right);
        } else os << "# ";
    }

    TreeNode* do_deseri(istringstream &is) {
        string val;
        is >> val;
        if (val == "#") return nullptr;
        else {
            TreeNode *root = new TreeNode(stoi(val));
            root->left = do_deseri(is);
            root->right = do_deseri(is);
            return root;
        }
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream os;
        do_seri(os, root);
        return os.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream is(data);
        return do_deseri(is);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));