class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        size_t lo = 0, hi = nums.size() - 1, mid = 0;
        while (lo < hi) {
            mid = (lo + hi) / 2;
            if (nums[mid] < nums[mid+1]) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        return lo;
    }
};