#include <vector>
#include <iostream>
using namespace std;

class Solution {
private:
    using vec_iter = vector<int>::iterator;
    void slice(vec_iter begin, vec_iter end, int limit) {
        if (end - begin < 1) return;
        auto mid = begin + (end - begin) / 2;
        swap(*mid, *begin);
        vec_iter eq_begin = begin, eq_end = end;
        for (auto iter = begin + 1; iter < eq_end; iter++) {
            while (iter != eq_end && *iter > *eq_begin) 
                swap(*iter, *--eq_end);
            if (*iter < *eq_begin)
                swap(*eq_begin++, *iter);
        }
        if (eq_end - eq_begin > limit) result.push_back(*eq_begin);
        if (eq_begin - begin > limit) slice(begin, eq_begin, limit);
        if (end - eq_end > limit) slice(eq_end, end, limit);
    }
public:
    vector<int> result;
    vector<int> majorityElement(vector<int>& nums) {
        result.clear();
        slice(nums.begin(), nums.end(), nums.size() / 3);
        return result;
    }
};

auto main() -> int {
    Solution s;
    vector<int> nums {1, 2, 2, 2, 2, 21, 1, 1, 13, 3, 4};
    vector<int> res = s.majorityElement(nums);
    for (auto& r: res)
        cout << r << " ";
    cout << endl;
}