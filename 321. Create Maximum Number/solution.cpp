class Solution {
private:
    vector<vector<int>> makeDP(vector<int> &nums) {
        int size = nums.size();
        vector<vector<int>> dp(size+1);
        dp[size] = nums;
        for (int i = size - 1; i >= 0; --i) {
            int flag = true;
            for (int j = 0; j < dp[i+1].size(); ++j) {
                if (flag && (j == dp[i+1].size() - 1 || dp[i+1][j] < dp[i+1][j+1])) {
                    flag = false;
                } else dp[i].push_back(dp[i+1][j]);
            }
        }
        return dp;
    }

    bool noLessThan(const vector<int> &nums1, int i, const vector<int> &nums2, int j) {
        while (i < nums1.size() && j < nums2.size() && nums1[i] == nums2[j]) {
            i++;
            j++;
        }
        return j == nums2.size() || (i < nums1.size() && nums1[i] > nums2[j]);
    }

    vector<int> combine(vector<int> nums1, vector<int> nums2) {
        int k = nums1.size() + nums2.size();
        vector<int> res(k);
        int i = 0, j = 0;
        for (int r = 0; r < k; r++) {
            if (noLessThan(nums1, i, nums2, j)) {
                res[r] = nums1[i++];
            } else {
                res[r] = nums2[j++];
            }
        }
        return res;
    }
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> dp1 = makeDP(nums1);
        vector<vector<int>> dp2 = makeDP(nums2);
        vector<int> res;
        for (int len1 = max((int) (k - nums2.size()), 0); len1 <= nums1.size() && len1 <= k; len1++) {
            vector<int> tmp = combine(dp1[len1], dp2[k-len1]);
            if (tmp >= res)
                res = std::move(tmp);
        }
        return res;
    }
};