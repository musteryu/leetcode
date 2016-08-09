class Solution {
private:
    void swap(int &a, int &b) {
        int tmp = a;
        a = b;
        b = tmp;
    }
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        vector<int> tmp(nums.end() - k, nums.end());
        for (auto it = nums.rbegin(); it != nums.rend(); it++) {
            *it = *(it + k);
        }
        for (auto to = nums.begin(), from = tmp.begin(); from != tmp.end(); to++, from++) {
            *to = *from;
        }
    }
};


// better

class Solution
{
public:
    void rotate(vector<int> &nums, int k) {
        reverse(nums.begin(), nums.end() - k);
        reverse(nums.end() - k, nums.end());
        reverse(nums.begin(), nums.end());
    }
    
};