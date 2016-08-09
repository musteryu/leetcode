#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        if (nums.empty()) return vector<int>();
        vector<int> product(nums.size());
        product[0] = 1;
        for (int i = 1; i < product.size(); i++) {
            product[i] = nums[i-1] * product[i-1];
        }
        int r = 1;
        for (int i = product.size()-2; i >= 0; i--) {
            r *= nums[i+1];
            product[i] *= r;
        }
        return product;
    }
};