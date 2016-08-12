#include <iostream>
#include <vector>
using namespace std;

class NumArray {
private:
    struct TreeNode {
        int begin, end, sum;
        TreeNode *left, *right;
        TreeNode(int begin, int end): begin(begin), end(end), 
                                    left(nullptr), right(nullptr), sum(0) {}
    };
    TreeNode *root;

    inline int rangeMid(int begin, int end) {
        return begin + (end - begin) / 2;
    }

    inline int nodeMid(TreeNode *node) {
        return rangeMid(node->begin, node->end);
    }

    TreeNode *make_tree(vector<int> &nums, int begin, int end) {
        if (begin >= end) return nullptr;
        TreeNode *t = new TreeNode(begin, end);
        if (end - begin < 2) 
            return (t->sum = nums[begin], t);
        int mid = rangeMid(begin, end);
        t->left = make_tree(nums, begin, mid);
        t->right = make_tree(nums, mid, end);
        t->sum = t->left->sum + t->right->sum;
        return t;
    }

    int update(TreeNode *node, int i, int val) {
        if (node->end - node->begin < 2) {
            return node->sum = val;
        } else {
            int mid = node->begin + (node->end - node->begin) / 2;
            if (i < mid) {
                return node->sum = update(node->left, i, val) + node->right->sum;
            } else {
                return node->sum = node->left->sum + update(node->right, i, val);
            }
        }
    }

    int sumRange(TreeNode *node, int begin, int end) {
        if (end - begin < 1) return 0;
        if (begin == node->begin && end == node->end) return node->sum;
        int mid = nodeMid(node);
        if (begin >= mid) 
            return sumRange(node->right, begin, end);
        else if (end <= mid)
            return sumRange(node->left, begin, end);
        else
            return sumRange(node->left, begin, mid) + sumRange(node->right, mid, end);
    }

public:
    NumArray(vector<int> &nums) {
        root = make_tree(nums, 0, nums.size());
    }

    void update(int i, int val) {
        root->sum = update(root, i, val);        
    }

    int sumRange(int i, int j) { 
        return sumRange(root, i, j+1);
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);


int main(int argc, char const *argv[])
{
    vector<int> nums {0,9,5,7,3};
    NumArray s(nums);
    cout << s.sumRange(4,4) << endl;
    cout << s.sumRange(2,4) << endl;
    cout << s.sumRange(3,3) << endl;
    s.update(4,5);
    s.update(1,7);
    s.update(0,8);
    cout << s.sumRange(1,2) << endl;
    s.update(1,9);
    cout << s.sumRange(4,4) << endl;
    s.update(3,4);
    return 0;
}



class NumArray {
private:
    vector<int> tree;
    vector<int> copy;

    int read(int treeidx) {
        int sum = 0;
        while (treeidx > 0) {
            sum += tree[treeidx];
            treeidx = treeidx & (treeidx - 1);
        }
        return sum;
    }
public:
    NumArray(vector<int> &nums): copy(nums.size(), 0) {
        int len = nums.size();
        if (!len) return;
        tree = vector<int>(len+1, 0);
        for (int i = 0; i < len; i++) {
            update(i, nums[i]);
        }
    }

    void update(int i, int val) {
        int diff = val - copy[i];
        copy[i] = val;
        int len = copy.size();
        i++;
        while (i <= len) {
            tree[i] += diff;
            i += (i & -i);
        }
    }

    int sumRange(int i, int j) { 
        return read(j+1) - read(i);
    }
};