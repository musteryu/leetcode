#include <algorithm>
#include <vector>
#include <cmath>
using std::count;
using std::vector;
using std::sqrt;

class Solution {
public:
    int countPrimes(int n) {
        if (n < 3) return 0;
        vector<bool> prime(n / 2 - 1, true); // prime[k] == true:  2*k + 3 is a prime number.
        int half = n / 2 - 1;
        int cnt = half;
        for (int i = 0; i * i < n; i++) {
            if (prime[i]) { // if k = 2 * i + 1 is a prime
                // mark k * k, k * (k + 2), ..., k * (k + 2l) as false
                // the index of k * k is 
                //  ((k * k) - 3) / 2 
                //= (4i^2 + 12i + 6) / 2 
                //= 2i^2 + 6i + 3 
                //= k*i+i+k
                for (int k = 2*i+3, j = k*i+i+k; j < half; j += k) {
                    if (prime[j]) {
                        cnt--;
                        prime[j] = false;
                    }
                }
            }
        }
        return cnt + 1;
    }
};