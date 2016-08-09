class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        int arr[26];
        memset(arr, 0, sizeof(int) * 26);
        for (auto &c: s)
            arr[c - 'a']++;
        for (auto &c: t)
            if (--arr[c-'a'] < 0) return false;
        return true;
    }
};