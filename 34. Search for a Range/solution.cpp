class Solution {
private:
    int bsearchLeft(vector<int> &nums, int target) {
        int low = 0, high = nums.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] >= target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
    int bsearchRight(vector<int> &nums, int target) {
        int low = 0, high = nums.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return high;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = bsearchLeft(nums, target);
        int right = bsearchRight(nums, target);  
        return left <= right ? vector<int> { left, right } : vector<int>{ -1, -1 };
    }
};