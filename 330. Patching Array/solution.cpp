class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int top = 1;
        long farthest = 0;
        int minCandidate = 0;
        int patch = 0;
        while (farthest < n) {
            top = farthest + 1;
            if (minCandidate < nums.size() && top >= nums[minCandidate]) {
                top = nums[minCandidate++];
            } else {
                patch++;
            }
            farthest += top;
        }
        return patch;
    }
};