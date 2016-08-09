#include <vector>
#include <iostream>
using std::vector;
using std::cout;
using std::endl;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int lmp = lastMaxPosition(nums);
        if (target <= nums[lmp] && target >= nums[0]) return bsearch(nums, 0, lmp, target);
        else if (lmp < nums.size() - 1 && target <= nums[nums.size()-1] && target >= nums[lmp+1])
            return bsearch(nums, lmp+1, nums.size()-1, target);
        else return false;
    }
    
    bool bsearch(vector<int>& nums, int low, int high, int target) {
        if (high < low) return false;
        int mid = (low + high) / 2;
        if (nums[mid] == target) return true;
        else if (nums[mid] < target) return bsearch(nums, mid + 1, high, target);
        else return bsearch(nums, low, mid - 1, target);
    }
    
    int lastMaxPosition(vector<int>& nums) {
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i+1] < nums[i]) return i;
        }
        return nums.size() - 1;
    }
};

int main(int argc, char const *argv[])
{
    int n[] = {2, 2, 0, 2, 2};
    vector<int> nums;
    for (int i: n) {
        nums.push_back(i);
    }
    cout << Solution().search(nums, 0) << endl;
    return 0;
}
