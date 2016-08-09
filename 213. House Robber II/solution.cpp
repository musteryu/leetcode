#include <vector>
using namespace std;

class Solution {
private:
    int rob(vector<int>::const_iterator begin, vector<int>::const_iterator end) {
        if (begin == end) return 0;
        int broken = 0, unbroken = 0, res = 0;
        for (auto iter = begin; iter != end; iter++) {
            res = std::max(unbroken + *iter, broken);
            unbroken = broken;
            broken = res;
        }
        return res;
    }
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        return std::max(rob(nums.cbegin(), nums.cend()-1), rob(nums.cbegin()+1, nums.cend()));
    }
};