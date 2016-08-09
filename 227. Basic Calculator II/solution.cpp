#include <string>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        int* ops = new int[s.size()];
        int* nums = new int[s.size()];
        int ops_top = -1, nums_top = -1;
        s += '+';
        for (int i = 0; i < s.size(); i++) {
            char& c = s[i];
            if (c >= '0' && c <= '9') {
                int num = 0;
                while (i < s.size() && s[i] >= '0' && s[i] <= '9')
                    num = num * 10 + s[i++] - '0';
                i--;
                if (ops_top >= 0 && ops[ops_top] == '*') {
                    nums[nums_top] *= num;
                    ops_top--;
                } else if (ops[ops_top] == '/') {
                    nums[nums_top] /= num;
                    ops_top--;
                } else {
                    nums[++nums_top] = num;
                }
            } else if (c == '+' || c == '-') {
                if (ops_top >= 0 && ops[ops_top] == '+') {
                    nums[nums_top-1] += nums[nums_top];
                    nums_top--;
                    ops[ops_top] = c;
                } else if (ops_top >= 0 && ops[ops_top] == '-') {
                    nums[nums_top-1] -= nums[nums_top];
                    nums_top--;
                    ops[ops_top] = c;
                } else {
                    ops[++ops_top] = c;
                }
            } else if (c == '*' || c == '/') {
                ops[++ops_top] = c;
            }
        }
        return nums[nums_top];
    }
};