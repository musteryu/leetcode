#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

class Solution {
private:
    vector<string> split(string &str) {
        vector<string> res;
        for (int l = 0, r = 1; r <= str.size(); r++) {
            if (str[r] == ' ' || r == str.size()) {
                res.push_back(str.substr(l, r-l));
                l = ++r;
            }
        }
        return res;
    }

public:
    bool wordPattern(string pattern, string str) {
        vector<string> p2s (26, "");
        map<string, char> s2p;
        int slen = str.size(), plen = pattern.size();
        if (!slen || !plen) return false;       
        vector<string> sp = split(str);
        if (sp.size() != plen) return false;
        for (int i = 0; i < plen; i++) {
            int pidx = pattern[i] - 'a';
            string sidx = sp[i];
            if (p2s[pidx] != "" && p2s[pidx] != sidx) return false;
            if (s2p.count(sidx) && s2p[sidx] != pidx + 'a') return false;
            p2s[pidx] = sp[i];
            s2p[sp[i]] = pidx + 'a';
        } 
        return true;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    string pattern("abba");
    string str("cat dog dog cat");
    cout << s.wordPattern(pattern, str);
    return 0;
}