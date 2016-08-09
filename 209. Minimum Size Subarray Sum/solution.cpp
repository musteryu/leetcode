#include <vector>
#include <algorithm>
using std::vector;
using std::min;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int len = nums.size();
        int start = 0, sum = 0, minLen = INT_MAX;
        for (int end = 0; end < len; end++) {
            sum += nums[end];
            while (sum >= s) {
                minLen = min(minLen, end - start + 1);
                sum -= nums[start++];
            }
        }
        return minLen == INT_MAX ? 0 : minLen;
    }
};