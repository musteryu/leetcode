class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> count(26, 0);
        vector<bool> visited(26, false);
        for (auto &ch: s) {
            count[ch-'a']++;
        }
        stack<char> stk;
        for (auto &ch: s) {
            count[ch-'a']--;
            if (visited[ch-'a'])
                continue;
            while (stk.size() && stk.top() > ch && count[stk.top()-'a'] > 0) {
                visited[stk.top() - 'a'] = false;
                stk.pop();
            }
            stk.push(ch);
            visited[ch-'a'] = true;
        }
        string reverse;
        while (stk.size()) {
            reverse.push_back(stk.top());
            stk.pop();
        }
        return string(reverse.crbegin(), reverse.crend());
    }
};