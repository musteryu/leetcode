class BinaryIndexedTree {
private:
    vector<int> sums;
    
public:
    BinaryIndexedTree(int sz): sums(sz+1, 0) {}

    void update(int treeIdx) {
        for (; treeIdx < sums.size(); treeIdx += treeIdx & (-treeIdx))
            ++sums[treeIdx];
    }

    int sum_of(int treeIdx) {
        int s = 0;
        for (; treeIdx > 0; treeIdx -= treeIdx & (-treeIdx))
            s += sums[treeIdx];
        return s;
    }
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> res(nums.size(), 0);
        unordered_map<int, int> rank;
        {
            int i = 0;
            for (auto &n: set<int>(nums.begin(), nums.end()))
                rank[n] = i++;
        }
        BinaryIndexedTree tree(rank.size());
        for (auto nback = nums.rbegin(), rback = res.rbegin()
            ; nback != nums.rend() && rback != res.rend()
            ; ++nback, ++rback
            ) {
            *rback = tree.sum_of(rank[*nback]);
            tree.update(rank[*nback] + 1);
        }
        return res;        
    }
};


class Solution {
private:
    struct Node {
        Node *left, *right;
        int leftAccess;
        int dup;
        int val;
        Node(int val): leftAccess(0), val(val), dup(1), left(nullptr), right(nullptr)
        {}
    };
    Node *root = nullptr;
    int insert(Node **handler, int val) {
        int cnt = 0;
        while (*handler) {
            if (val == (*handler)->val) {
                (*handler)->dup++;
                return cnt + (*handler)->leftAccess;
            } else if (val > (*handler)->val) {
                cnt += ((*handler)->leftAccess + (*handler)->dup);
                handler = &(*handler)->right;
            } else {
                (*handler)->leftAccess++;
                handler = &(*handler)->left;
            }
        }
        *handler = new Node(val);
        return cnt;
    }
public:
    vector<int> countSmaller(vector<int> &nums) {
        vector<int> res(nums.size(), 0);
        for (int i = nums.size()-1; i >= 0; --i) {
            res[i] = insert(&root, nums[i]);
        }
        return res;
    }
};