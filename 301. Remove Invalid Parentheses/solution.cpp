class Solution {
private:
    vector<string> res;
    void dfs(const string &s, int last_fast, int last_slow, pair<char, char> par) {
        for (int stack = 0, fast = last_fast; fast < s.size(); fast++) {
            if (s[fast] == par.first) stack++;
            if (s[fast] == par.second) stack--;
            if (stack < 0) {
                for (int slow = last_slow; slow <= fast; slow++) {
                    if (s[slow] == par.second && (slow == last_slow || s[slow-1] != par.second))
                        dfs(s.substr(0, slow) + s.substr(slow+1), fast, slow, par);
                }
                return;
            }
        }
        string r (s.rbegin(), s.rend());
        if (par.first == '(') {
            dfs(r, 0, 0, make_pair(')', '('));
        } else {
            res.push_back(r);
        }
    }
public:
    vector<string> removeInvalidParentheses(string s) {
        res.clear();      
        dfs(s, 0, 0, make_pair('(', ')'));
        return res;
    }
};
