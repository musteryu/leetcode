#include <set>

class Solution {
public:
    bool isHappy(int n) {
        std::set<int> s;
        while (n != 1) {
            int sum = 0;
            while (n != 0) {
                sum += (n % 10) * (n % 10);
                n /= 10;
            }
            n = sum;
            if (s.count(n)) return false;
            s.insert(n);
        }
        return true;
    }
};