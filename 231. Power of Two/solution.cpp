class Solution {
public:
    bool isPowerOfTwo(int n) {
        bool bit = false;
        while (n != 0) {
            if (n & 1) {
                if (bit) return false;
                else bit = true;
            }
            n >>= 1; 
        }
        return bit;
    }
};