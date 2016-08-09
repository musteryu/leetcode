#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
private:
    inline bool isDigit(char& c) {
        return (c - '0' >= 0 && c - '9' <= 0);
    }
    inline bool isOperator(char& c) {
        return c == '+' || c == '-';
    }
    inline bool cal(int& num1, int& num2, char& op) {
        switch (op) {
            case '+':
                num1 += num2;
                return true;
            case '-':
                num1 -= num2;
                return true;
            default:
                return false;
        }
    }
public:
    int calculate(string s) {
        int* nums_stack = new int[s.size()];
        int nums_top_idx = -1;
        char* ops_stack = new char[s.size()];
        int ops_top_idx = -1;

        for (int i = 0; i < s.size();) {
            char& c = s[i];
            if (c == ' ') {
                i++;
                continue;
            }
            if (isDigit(c)) {
                int j;
                for (j = i+1; isDigit(s[j]); j++);
                nums_stack[++nums_top_idx] = stoi(s.substr(i, j-i));
                if (ops_top_idx >= 0) {
                    if (cal(nums_stack[nums_top_idx-1], nums_stack[nums_top_idx], ops_stack[ops_top_idx])) {
                        nums_top_idx--;
                        ops_top_idx--;
                    }
                }
                i = j;
            } else if (isOperator(c) || c == '(') {
                ops_stack[++ops_top_idx] = c;
                i++;
            } else { // )
                ops_top_idx--;
                while (cal(nums_stack[nums_top_idx-1], nums_stack[nums_top_idx], ops_stack[ops_top_idx])) {
                    nums_top_idx--;
                    ops_top_idx--;
                }
                i++;
            }
        }
        int res = nums_stack[nums_top_idx];
        delete[] nums_stack;
        delete[] ops_stack;
        return res;
    }
};


class Solution1 {
public:
    int calculate(string s) 
    {
        int total = 0;
        // int* signs = new int[s.size()];
        int signs[10000000];
        int sg_top = 1;
        signs[0] = 1;
        signs[1] = 1;
        for (int i = 0; i < s.size(); i++) {
            char& c = s[i];
            if (c >= '0' && c <= '9') 
            {
                int num = 0;
                while (i < s.size() && s[i] >= '0' && s[i] <= '9')
                    num = 10 * num + s[i++] - '0';
                total += num * signs[sg_top--];
                i--;
            } 
            else if (c == ')')
            {
                sg_top--;
            }
            else if (c != ' ')
            {
                int sg_new = signs[sg_top] * (c == '-' ? -1 : 1);
                signs[++sg_top] = sg_new;
            }
        }
        return total;
    }
};

auto main() -> int {
    Solution1 s;
    cout << s.calculate("0") << endl;
}