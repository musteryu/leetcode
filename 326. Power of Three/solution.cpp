constexpr int maxValue = pow(3, (int)(log(INT_MAX) / log(3)));
class Solution {
public:
    bool isPowerOfThree(int n) {
        return n > 0 && maxValue % n == 0; 
    }
};
