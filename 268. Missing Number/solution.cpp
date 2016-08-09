class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0, len = nums.size();
        for (auto &n: nums)
            sum += n;
        return len * (len + 1) / 2 - sum;
    }
};
