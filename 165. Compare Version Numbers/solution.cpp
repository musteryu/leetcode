#include <string>
#include <vector>
#include <iostream>
using std::string;
using std::vector;
using std::cout;
using std::endl;

class Solution {
private:
    vector<int> splitToInts(string version) {
        vector<int> ret;
        string::size_type start = 0;
        auto pos = version.find('.');
        while (pos != string::npos) {
            ret.push_back(std::stoi(version.substr(start, pos - start)));
            start = pos+1;
            pos = version.find('.', start);
        }
        ret.push_back(std::stoi(version.substr(start)));
        return ret;
    }
public:
    int compareVersion(string version1, string version2) {
        vector<int> ints1 = splitToInts(version1);
        vector<int> ints2 = splitToInts(version2);
        int i1 = 0, i2 = 0;
        while (i1 < ints1.size() && i2 < ints2.size()) {
            if (ints1[i1] < ints2[i2]) return -1;
            if (ints1[i1] > ints2[i2]) return 1;
            i1 ++;
            i2 ++;
        }
        while (i1 < ints1.size()) {
            if (ints1[i1++] != 0) return 1;
        }
        while (i2 < ints2.size()) {
            if (ints2[i2++] != 0) return -1;
        }
        return 0;
    }
};

int main(int argc, const char * args[]) {
    string version1 = args[1];
    string version2 = args[2];
    cout << Solution().compareVersion(version1, version2) << endl;
}