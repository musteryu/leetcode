#include <vector>
#include <queue>
#include <memory>
#include <iostream>
#include <cmath>
using namespace std;

class Solution1 {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        BinarySearchTree btree;
        for (int i = 0; i < nums.size(); i++) {
            if (btree.search_or_add(Node(nums[i], t)))
                return true;
            //btree.debug();
            if (btree.size() > k) {
                btree.del(Node(nums[i-k], t));
            }
        }
        return false;
    }
private:
    class Node {
    public:
        int lower_bound;
        int upper_bound;
        int value;
        unique_ptr<Node> left;
        unique_ptr<Node> right;
        Node (int v, int t): value(v),
                            lower_bound(v-t), 
                            upper_bound(v+t), 
                            left(nullptr), 
                            right(nullptr) 
        {}
        Node (Node&& other): value(other.value),
                            lower_bound(other.lower_bound),
                            upper_bound(other.upper_bound),
                            left(std::move(other.left)),
                            right(std::move(other.right))
        {}
        bool within(Node& node) const {
            return value >= node.lower_bound && value <= node.upper_bound;
        }
        bool operator>(const Node& node) const {
            return value > node.upper_bound;
        }
        bool operator<(const Node& node) const {
            return value < node.lower_bound;
        }
        bool operator==(const Node& node) const {
            return value == node.value;
        }
        void reset_value(const Node& other) {
            value = other.value;
            lower_bound = other.lower_bound;
            upper_bound = other.upper_bound;
        }
    };

    class BinarySearchTree {
    private:
        unique_ptr<Node> root;
        int size_;
        unique_ptr<Node> delete_min(unique_ptr<Node>& root) {
            if (root->left == nullptr) {
                size_ --;
                return std::move(root->right);
            }
            root->left = delete_min(root->left);
            return std::move(root);
        }

        Node& min(Node& root) {
            Node* min_root = &root;
            while (min_root->left != nullptr) {
                min_root = min_root->left.get();
            }
            return *min_root;
        }

        unique_ptr<Node> del(unique_ptr<Node>& root, Node&& key) {
            if (root == nullptr) return nullptr;
            if (key < *root) root->left = del(root->left, std::move(key));
            else if (key > *root) root->right = del(root->right, std::move(key));
            else {
                if (root->right == nullptr) return std::move(root->left);
                if (root->left == nullptr) return std::move(root->right);
                root->reset_value(min(*(root->right)));
                root->right = delete_min(root->right);
            }
            return std::move(root);
        }
    public:
        BinarySearchTree(): root(nullptr), size_(0) {}
        bool search_or_add(Node&& node) {
            if (root == nullptr) {
                root.reset(new Node(std::move(node)));
                size_++;
                return false;
            }
            Node* iter = root.get();
            while (iter != nullptr) {
                if (node.within(*iter))
                    return true;
                if (node > *iter) {
                    if (iter->right == nullptr) {
                        iter->right.reset(new Node(std::move(node)));
                        break;
                    }
                    iter = iter->right.get();
                }
                else {
                    if (iter->left == nullptr) {
                        iter->left.reset(new Node(std::move(node)));
                        break;
                    }
                    iter = iter->left.get();
                }
            }
            
            size_++;
            return false;
        }

        void del(Node&& key) {
            root = del(root, std::move(key));
        }

        const int size() const {
            return size_;
        }

        void debug() {
            if (root == nullptr) cout << "root is nullptr" << endl;
            else
            cout << "root: " << "(" << root->lower_bound << ", " << root->value << ", " << root->upper_bound << ")" << endl;
        }
    };
};

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (k < 1 || t < 0) return false;
        int min_num = INT_MAX;
        int max_num = INT_MIN;
        for (auto& num: nums) {
            min_num = std::min(min_num, num);
            max_num = std::max(max_num, num);
        }
        long long bucket_width = static_cast<long long>(t) + 1;
        int size = (static_cast<long long>(max_num) - static_cast<long long>(min_num)) / bucket_width + 1;
        int* bucket = new int[size];
        memset(bucket, -1, sizeof(int) * size);
        for (int i = 0; i < nums.size(); i++) {
            int bucket_idx = (static_cast<long long>(nums[i])-min_num) / bucket_width;
            if (bucket[bucket_idx] >= 0)
                return true;
            bucket[bucket_idx] = i;
            if (bucket_idx >= 1) {
                int j = bucket[bucket_idx-1];
                if (j >= 0 && abs(static_cast<long long>(nums[i]) - nums[j]) <= t)
                    return true;
            }
            if (bucket_idx < size-1) {
                int l = bucket[bucket_idx+1];
                if (l >= 0 && abs(static_cast<long long>(nums[i]) - nums[l]) <= t)
                    return true;
            }
            if (i >= k) {
                bucket[(nums[i-k] - min_num) / bucket_width] = -1;
            }
        }
        return false;
    }
};

int main() {
    Solution s;
    vector<int> nums = {-1, 2147483647};
    cout << s.containsNearbyAlmostDuplicate(nums, 1, 2147483647) << endl;
}