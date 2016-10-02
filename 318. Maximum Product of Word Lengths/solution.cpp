class Solution {
private:
    inline int word2bits(string &word) {
        int i = 0;
        for (auto &ch: word)
            i |= 1 << (ch-'a');
        return i;
    }

public:
    int maxProduct(vector<string>& words) {
        vector<int> bits(words.size());
        sort(words.begin(), words.end(), [](const string &a, const string &b) -> bool {
            return b.size() < a.size();
        });
        for (int i = 0; i < words.size(); ++i) {
            bits[i] = word2bits(words[i]);
        }
        string::size_type max_product = 0;
        int size = words.size();
        for (int i = 0; i < size-1; ++i) {
            for (int j = i+1; j < size; ++j) {
                if (bits[i] & bits[j]) continue;
                max_product = std::max(max_product, words[i].size() * words[j].size());
            }
        }
        return max_product;
    }
};