#include <string>
#include <iostream>
using std::cout;
using std::endl;
using std::string;

class Solution {
public:
    char *alpha = "ZABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string convertToTitle(int n) {
        string res;
        while (n > 0) {
            res.push_back('A' + (n - 1) % 26);
            n = (n - 1) / 26;
        }
        std::reverse(res.begin(), res.end());
        return res;
    }
};

int main(int argc, char const *argv[])
{
    int n = 26;
    cout << Solution().convertToTitle(n) << endl;
    return 0;
}