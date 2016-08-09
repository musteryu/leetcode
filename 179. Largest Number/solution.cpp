class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> num_strs(nums.size());
        std::transform(nums.begin(), nums.end(), num_strs.begin(), 
            [](int i) -> string {
                return to_string(i);
            });
        std::sort(num_strs.begin(), num_strs.end(), [](string a, string b) {
            return a + b > b + a;
        });
        string result;
        for (auto &str: num_strs)
            result += str;
        if (result[0] == '0') return "0";
        else return result;
    }
};