class Solution {
private:
    int merge(vector<long> &sums, int begin, int end, int lower, int upper) {
        if (end - begin < 2) return 0;
        int mid = begin + (end - begin) / 2;
        int count = merge(sums, begin, mid, lower, upper) + 
                    merge(sums, mid, end, lower, upper);
        int range_begin = mid, range_end = mid, t = mid;
        vector<long> merged(end - begin);
        int merged_top = 0;
        for (int i = begin; i < mid; ++i) {
            while (range_begin < end && sums[range_begin] - sums[i] < lower) ++range_begin;
            while (range_end < end && sums[range_end] - sums[i] <= upper) ++range_end;
            count += range_end - range_begin;
            while (t < end && sums[t] < sums[i]) 
                merged[merged_top++] = sums[t++];
            merged[merged_top++] = sums[i];
        }
        for (int s = 0, d = begin; s < merged_top; ++s, ++d) {
            sums[d] = merged[s];
        }
        return count;
    }
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int len = nums.size();
        vector<long> sums(len+1);
        for (int i = 0; i < len; ++i) {
            sums[i+1] = sums[i] + (long)nums[i];
        }
        return merge(sums, 0, len+1, lower, upper);
    }
};