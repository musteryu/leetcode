class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int l = -1, r = -1;
        while (nums[++l] != 0);
        r = l;
        for (int i = l + 1; i < nums.size(); i++) {
            if (nums[i] == 0) r++;
            else {
                swap(nums[i], nums[l]);
                l++;
                r++;
            }
        }
    }
};
