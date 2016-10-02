class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = 0;
        vector<int> nozero {1};
        for (auto &num: nums) {
            if (num != 0) {
                nozero.push_back(num);
                n++;
            }
        }
        nozero.push_back(1);
        vector<vector<int>> sum(n+2, vector<int>(n+2));
        for (int gap = 2; gap <= n + 1; ++gap) {
            for (int left = 0; left + gap <= n + 1; ++left) {
                int right = left + gap;
                for (int i = left+1; i < right; i++) {
                    sum[left][right] = max(
                        sum[left][right], 
                        sum[left][i] + nozero[left] * nozero[i] * nozero[right] + sum[i][right]
                    );
                }
            }
        }
        return sum.front().back();
    }
};

class Solution {
private:
    int burst(vector<vector<int>> &sum, vector<int> &nums, int left, int right) {
        if (right - left < 2) return 0;
        if (sum[left][right]) return sum[left][right];
        int ans = 0;
        for (int i = left+1; i < right; ++i) {
            ans = max(
                ans,
                burst(sum, nums, left, i) + nums[left]*nums[i]*nums[right] +
                burst(sum, nums, i, right)
            );
        }
        return sum[left][right] = ans;
    }
public:
    int maxCoins(vector<int> &nums) {
        vector<int> balloons {1, 1};
        balloons.insert(balloons.begin()+1, nums.begin(), nums.end());
        int n = balloons.size();
        vector<vector<int>> sum (n, vector<int>(n));
        return burst(sum, balloons, 0, n-1);
    }
};