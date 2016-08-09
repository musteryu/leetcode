class Solution {
public:
    inline int addDigits(int num) {
        return (num - 1) % 9 + 1;
    }
};