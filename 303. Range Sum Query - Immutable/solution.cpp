class NumArray {
private:
    vector<int> sums;
public:
    NumArray(vector<int> &nums): sums(nums.size(), 0) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            sums[i] = sum;
        }
    }

    int sumRange(int i, int j) {
        if (i == 0) return sums[j];
        else return sums[j] - sums[i-1];
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);