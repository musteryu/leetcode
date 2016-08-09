class Solution {
public:
    int findMin(vector<int>& nums) {
        int minNum = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[i-1]) 
                return std::min(minNum, nums[i]);
        }
        return minNum;
    }
};