class Solution {
private:
    vector<string> res;
    void dfs(const string& num, const int target, string cur, int pos, const long cv, const long pv, const char op) {
        if (pos == num.size() && cv == target) {
            res.push_back(cur);
        } else {
            for (int i=pos+1; i<=num.size(); i++) {
                string t = num.substr(pos, i-pos);
                long now = stol(t);
                if (to_string(now) != t) continue;
                dfs(num, target, cur+'+'+t, i, cv+now, now, '+');
                dfs(num, target, cur+'-'+t, i, cv-now, now, '-');
                dfs(num, target, cur+'*'+t, i, (op == '-') ? cv+pv - pv*now : ((op == '+') ? cv-pv + pv*now : pv*now), pv*now, op);
            }
        }
    }

public:
    vector<string> addOperators(string num, int target) {
        res.clear();
        for (int i = 1; i <= num.size(); i++) {
            string s = num.substr(0, i);
            long cur = stol(s);
            if (to_string(cur) != s) continue;
            dfs(num, target, s, i, cur, cur, '#');
        }
        return res;
    }
};
