#include <list>

class Solution {
private:
    void push(list<int>& l, int n) {
        while (!l.empty() && l.back() < n) 
            l.pop_back();
        l.push_back(n);
    }

    void pop(list<int>& l, int n) {
        if (l.front() == n)
            l.pop_front();
    }

public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (nums.size() == 0 || k == 0) return vector<int>();
        list<int> l;
        vector<int> maxs(nums.size() - k + 1, 0);
        for (int i = 0; i < k; i++)
            push(l, nums[i]);
        maxs[0] = l.front();
        for (int i = 1; i <= nums.size() - k; i++) {
            pop(l, nums[i-1]);
            push(l, nums[i-1+k]);
            maxs[i] = l.front();
        }
        return maxs;
    }
};