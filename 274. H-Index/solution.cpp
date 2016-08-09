class Solution {
public:
    int hIndex(vector<int>& citations) {
        int len = citations.size();
        vector<int> count (len+1);
        for (auto &c: citations)
            if (c > len)
                count[len]++;
            else count[c]++;
        int total = 0;
        for (int i = len; i >= 0; i--) {
            total += count[i];
            if (total >= i) return i;
        }
        return 0;
    }
};

