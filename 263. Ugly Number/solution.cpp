class Solution {
public:
    bool isUgly(int num) {
        if (num <= 0) return false;
        for (int f: {2, 3, 5}) {
            while (!(num % f))
                num /= f;
        }
        return num == 1;
    }
};
