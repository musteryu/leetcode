class Solution {
private:
    typedef vector<int>::iterator iterator;
    iterator bsearch(iterator bgn, iterator end, int v) {
        while (bgn < end) {
            iterator mid = bgn + (end - bgn) / 2;
            if (*mid >= v) {
                end = mid;
            } else {
                bgn = mid + 1;
            }
        }
        return bgn;
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> res;
        for (auto &n: nums) {
            auto it = bsearch(res.begin(), res.end(), n);
            if (it == res.end()) res.push_back(n);
            else *it = n;
        }
        return res.size();
    }
};