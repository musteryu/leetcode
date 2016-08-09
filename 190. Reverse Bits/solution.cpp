#define uint32_t unsigned int

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        for (uint32_t l = 0x80000000, r = 0x00000001, cnt = 0
            ; cnt < 32
            ; l >>= 1, r <<= 1, cnt++) 
        {
            if (n & r) res |= l;
        }
        return res;
    }
};


// best solution
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        n = (n >> 16) | (n << 16);
        n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);
        n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);
        n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);
        n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);
        return n;
    }
};

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        for(int i = 0; i < 32; i++){
            result <<= 1;
            result += n&1;
            n >>= 1;
        }
    }
}