class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int res = 0;
        for (uint32_t bit = 1 << 31; bit != 0; bit >>= 1) {
            uint32_t m_bit = m & bit;
            uint32_t n_bit = n & bit;
            if (m_bit ^ n_bit) break;
            res |= (m_bit & n_bit);
        }
        return res;
    }
};

// better

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int shift = 0;
        if (m == 0) return 0;
        while (m != n) {
            m >>= 1;
            n >>= 1;
            ++shift;
        }
        return m << shift;
    }
};

// not bad
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        while (n > m) {
            n &= n - 1;
        }
        return n;
    }
};