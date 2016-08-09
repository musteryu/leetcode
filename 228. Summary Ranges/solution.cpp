#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        for (int i = 0; i < nums.size(); i++) {
            int& lower = nums[i];
            for (; i < nums.size()-1 && nums[i] + 1 == nums[i+1]; i++);
            int& higher = nums[i];
            if (lower == higher) result.push_back(to_string(lower));
            else result.push_back(to_string(lower) + "->" + to_string(higher));
        }
        return result;
    }
};