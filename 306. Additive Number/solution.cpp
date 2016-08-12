#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
private:
    bool isAdditive(string &num, int pos, string &num1, string &num2) {
        if (pos >= num.size()) return true;
        string sum = to_string(stol(num1) + stol(num2));
        if (num.substr(pos, sum.size()) != sum) return false;
        else return isAdditive(num, pos + sum.size(), num2, sum);
    }
public:
    bool isAdditiveNumber(string num) {
        int len = num.size();
        for (int i = 1; i <= len / 2; i++) {
            if (num[0] == '0' && i > 1) break;
            string num1 = num.substr(0, i);
            for (int j = i + 1; len - j >= max(j-i, i); j++) {
                if (num[i] == '0' && j - i > 1) break;
                string num2 = num.substr(i, j-i);
                if (isAdditive(num, j, num1, num2)) return true;
            }
        }
        return false;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    cout << s.isAdditiveNumber("112358") << endl;
    return 0;
}