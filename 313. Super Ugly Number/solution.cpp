class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> ugly(n, 1);
        int k = primes.size();
        vector<int> ptr(k, 0);
        for (int i = 1; i < n; i++) {
            int min_ugly = INT_MAX;
            for (int j = 0; j < k; j++) {
                min_ugly = min(min_ugly, ugly[ptr[j]] * primes[j]);
            }
            ugly[i] = min_ugly;
            for (int j = 0; j < k; j++) {
                if (ugly[i] == ugly[ptr[j]] * primes[j])
                    ptr[j]++;
            }
        }
        return ugly[n-1];
    }
};