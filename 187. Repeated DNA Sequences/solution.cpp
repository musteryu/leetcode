class Solution {
private:
    inline int getBits(char &c) {
        switch (c) {
            case 'A': return 0;
            case 'C': return 1;
            case 'G': return 2;
            case 'T': return 3;
            default: return 0;
        }
    }
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int arr[0x100000] = {0};
        int key = 0;
        vector<string> answer;
        for (int i = 0; i < s.size(); i++) {
            key = (key << 2 | getBits(s[i])) & 0xfffff;
            if (i < 9) continue;
            if (arr[key] == 1)
                answer.push_back(s.substr(i-9, 10));
            arr[key]++;
        }
        return answer;
    }
};