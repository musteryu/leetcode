#include <cmath>
using namespace std;

class Solution {
public:
    int countDigitOne(int n) {
        int abcde = n;
        int digits = 0;
        while (n) {
            digits++;
            n /= 10;
        }
        return count(abcde, digits);
    }
private:
    int count(int abcde, int digits) {
        if (digits == 0) return 0;
        if (digits == 1) return abcde >= 1;
        // define n as abcde
        int l0000 = pow(10, digits-1);
        int a = abcde / l0000;
        int bcde = abcde - a * l0000;
        return pow(10, digits-2) * a * (digits - 1) + count(a-1, 1) * l0000 // count (00000 ~ (a-1)9999)
        + (a == 1) * (bcde + 1) + count(bcde, digits-1); 
        // count (a0000 ~ abcde) == count (a-1 ~ a) * bcde + count(00000 ~ 0bcde)
    }
};

class BetterSolution {
public:
    int countDigitOne(int n) {
        int ones = 0;
        for (long long m = 1; m <= n; m *= 10) {
            ones += (n / m + 8) / 10 * m + (n / m % 10 == 1) * (n % m + 1); 
        }
        return ones;
    }
}