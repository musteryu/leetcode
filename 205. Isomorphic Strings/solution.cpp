#include <string>
using std::string;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int map[256];
        bool marked[256];
        for (auto &ch: map)
            ch = -1;
        for (auto &bl: marked)
            bl = false;
        string::size_type len = s.size();
        if (len != t.size()) return false;
        for (string::size_type i = 0; i < len; i++) {
            if (map[s[i]] < 0) {
                map[s[i]] = t[i];
                if (marked[t[i]]) return false;
                marked[t[i]] = true;
            }
            if (map[s[i]] != t[i]) return false;
        }
        return true;   
    }
};

bool isIsomorphic(string s, string t) {
    char s_t[128], t_s[128];
    memset(s_t, 0, 128);
    memset(t_s, 0, 128);
    int size = s.size();
    for(int i = 0; i < size; ++i){
        if( s_t[ s[i] ] != 0 && s_t[ s[i] ] != t[i] ) return false;
        if( t_s[ t[i] ] != 0 && t_s[ t[i] ] != s[i] ) return false;
        s_t[ s[i] ] = t[i];
        t_s[ t[i] ] = s[i];
    }
        
    return true;
}