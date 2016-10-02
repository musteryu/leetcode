class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> index;
        for (int i = 0; i < nums.size(); i++) {
            int n = nums[i];
            if (index.count(target - n)) {
                return vector<int> { index[target-n], i };
            } else {
                index[n] = i;
            }
        }
        return vector<int> {};
    }
};