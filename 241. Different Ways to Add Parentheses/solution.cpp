class Solution {
private:
    inline int compute(int a, int b, char op) {
        switch (op) {
            case '+': return a + b;
            case '-': return a - b;
            case '*': return a * b;
            default: return -1;
        }
    }
public:
    vector<int> diffWaysToCompute(string input) {
        if (input.empty()) return vector<int>();
        vector<int> res;
        for (int i = 0; i < input.size(); i++) {
            switch (input[i]) {
                case '0'...'9': break;
                default: {
                    auto vec1 = diffWaysToCompute(input.substr(0, i));
                    auto vec2 = diffWaysToCompute(input.substr(i+1));
                    for (auto r1: vec1) {
                        for (auto r2: vec2) {
                            res.push_back(compute(r1, r2, input[i]));
                        }
                    }
                }
            }
        }
        return res.empty() ? vector<int>{ stoi(input) } : res;
    }
};