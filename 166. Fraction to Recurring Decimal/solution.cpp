#include <string>
#include <map>
#include <iostream>
using std::string;
using std::to_string;
using std::map;
using std::cout;
using std::endl;

class Solution {
public:
    string fractionToDecimal(int64_t n, int64_t d) {
        if (n == 0) return "0";
        string res;
        if ((n < 0) ^ (d < 0)) res.push_back('-');
        n = n < 0 ? -n : n;
        d = d < 0 ? -d : d;
        res += to_string(n / d);
        if (n % d == 0) return res;
        res.push_back('.');
        map<int, int> m;
        for (int64_t r = n % d; r; r %= d) {
            if (m.count(r) > 0) {
                res.insert(m[r], 1, '(');
                res.push_back(')');
                break;
            }
            m[r] = res.size();
            r *= 10;
            res += to_string(r / d);
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    int n = 0;
    int d = 3;
    cout << Solution().fractionToDecimal(n, d) << endl;
    return 0;
}