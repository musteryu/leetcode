#include <iostream>
#include <vector>

using namespace std;

/**
class Solution {
    int majorityElement(vector<int> &nums, int min_n, int max_n) {
        if (min_n == max_n) return min_n;
        vector<int> left, right;
        int left_max_n = INT_MIN, left_min_n = INT_MAX;
        int right_max_n = INT_MIN, right_min_n = INT_MAX;
        int mid = (max_n + min_n) / 2;
        for (auto &n: nums) {
            if (n <= mid) {
                left.push_back(n);
                left_max_n = max(left_max_n, n);
                left_min_n = min(left_min_n, n);
            } else {
                right.push_back(n);
                right_max_n = max(right_max_n, n);
                right_min_n = min(right_min_n, n);
            }
        }
        if (left.size() > nums.size() / 2) return majorityElement(left, left_min_n, left_max_n);
        else return majorityElement(right, right_min_n, right_max_n);
    }
public:
    int majorityElement(vector<int>& nums) {
        int min_n = INT_MAX, max_n = INT_MIN;
        for (auto &n: nums) {
            min_n = min(min_n, n);
            max_n = max(max_n, n);
        }
        return majorityElement(nums, min_n, max_n);
    }
};
**/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int min_n = INT_MAX, max_n = INT_MIN;
        for (auto &n: nums) {
            min_n = min(min_n, n);
            max_n = max(max_n, n);
        }
        vector<int> majority = nums;
        while (min_n != max_n) {
            int mid_n = (max_n + min_n) / 2;
            int left_max_n = INT_MIN, right_max_n = INT_MIN;
            int left_min_n = INT_MAX, right_min_n = INT_MAX;
            vector<int> left, right;
            for (auto &n: majority) {
                if (n <= mid_n) {
                    left.push_back(n);
                    left_max_n = max(left_max_n, n);
                    left_min_n = min(left_min_n, n);
                } else {
                    right.push_back(n);
                    right_max_n = max(right_max_n, n);
                    right_min_n = min(right_min_n, n);
                }
            }
            if (left.size() > majority.size() / 2) {
                majority = left;
                min_n = left_min_n;
                max_n = left_max_n;
            } else {
                majority = right;
                min_n = right_min_n;
                max_n = right_max_n;
            }
        }
        return min_n;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums = {47,47,72,47,72,47,79,47,12,92,13,47,47,83,33,15,18,47,47,47,47,64,47,65,47,47,47,47,70,47,47,55,47,15,60,47,47,47,47,47,46,30,58,59,47,47,47,47,47,90,64,37,20,47,100,84,47,47,47,47,47,89,47,36,47,60,47,18,47,34,47,47,47,47,47,22,47,54,30,11,47,47,86,47,55,40,49,34,19,67,16,47,36,47,41,19,80,47,47,27};
    cout << Solution().majorityElement(nums) << endl;
    return 0;
}