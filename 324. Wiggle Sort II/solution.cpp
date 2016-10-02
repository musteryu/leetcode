class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int len = nums.size();
        auto mid_ptr = nums.begin() + len / 2;
        nth_element(nums.begin(), mid_ptr, nums.end());
        int mid = *mid_ptr;
        #define virt(i) (((i) * 2 + 1) % (len | 1))
        int low = 0, high = len-1, cur = 0;
        while (cur <= high) {
            if (nums[virt(cur)] > mid) {
                swap(nums[virt(low++)], nums[virt(cur++)]);
            } else if (nums[virt(cur)] < mid) {
                swap(nums[virt(cur)], nums[virt(high--)]);
            } else {
                cur++;
            }
        }
    }
}