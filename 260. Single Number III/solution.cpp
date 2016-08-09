class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int x = 0;
        for (auto &n: nums)
            x ^= n;
        int lsb = x & (-x);
        int t = 0, f = 0;
        for (auto &n: nums)
            if (n & lsb) t ^= n;
            else f ^= n;
        return vector<int> { f, t };
    }
};
