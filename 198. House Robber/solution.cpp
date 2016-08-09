#include <vector>
using std::vector;

class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        if (!len) return 0;
        vector<int> unbroken(len), broken(len);
        unbroken[0] = 0;
        broken[0] = nums[0];
        for (int i = 1; i < len; i++) {
            unbroken[i] = std::max(unbroken[i-1], broken[i-1]);
            broken[i] = std::max(unbroken[i-1] + nums[i], broken[i-1]);
        }
        return std::max(unbroken[len - 1], broken[len - 1]);
    }
};
