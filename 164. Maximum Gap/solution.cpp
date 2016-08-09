#include <vector>
#include <algorithm>
#include <iostream>
using std::vector;

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.empty() || nums.size() == 1) return 0;
        int min_v = INT_MAX, max_v = INT_MIN;
        for (auto &num: nums) {
            if (num < min_v) min_v = num;
            if (num > max_v) max_v = num;
        }
        double gap = (max_v - min_v - 1) / (nums.size() - 1) + 1;
        vector<int> max_buckets(nums.size() - 1, INT_MIN);
        vector<int> min_buckets(nums.size() - 1, INT_MAX);
        for (auto &num: nums) {
            if (num != min_v && num != max_v) {
                int idx = (num - min_v) / gap;
                if (num > max_buckets[idx]) max_buckets[idx] = num;
                if (num < min_buckets[idx]) min_buckets[idx] = num;
            }
        }

        int max_gap = INT_MIN, last = min_v;
        for (int idx = 0; idx < max_buckets.size(); idx++) {
            if (max_buckets[idx] == INT_MIN) continue;
            max_gap = std::max(max_gap, min_buckets[idx] - last);
            last = max_buckets[idx];
        }
        return std::max(max_gap, max_v - last);
    }
};

int main(int argc, const char* args[]) {
    vector<int> nums {1,1000000};
    std::cout << Solution().maximumGap(nums) << std::endl;
}