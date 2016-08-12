class Solution {
public:
    string getHint(string secret, string guess) {
        int a = 0, b = 0;
        vector<int> scnt(10, 0), gcnt(10, 0);
        for (int i = 0; i < guess.size(); i++) {
            auto s = secret[i];
            auto g = guess[i];
            if (s == g) a++;
            else {
                scnt[s-'0']++;
                gcnt[g-'0']++;
            }
        }

        for (int i = 0; i < 10; i++) {
            b += min(scnt[i], gcnt[i]);
        }
        return to_string(a) + "A" + to_string(b) + "B";
    }
};