class Solution {
private:
    const string ones[10] = {"", "One ", "Two ", "Three ", "Four ", "Five ", "Six ", "Seven ", "Eight ", "Nine "};
    const string teens[10] = { "Ten ", "Eleven ", "Twelve ", "Thirteen ", "Fourteen ", "Fifteen ", "Sixteen ", "Seventeen ",
        "Eighteen ", "Nineteen " };
    const string ties[10] = { "#", "#", "Twenty ", "Thirty ", "Forty ", "Fifty ", "Sixty ", "Seventy ", "Eighty ", "Ninety " };

    string procChunk(int chunk) {
        string res;
        if (chunk / 100 > 0) {
            res += ones[chunk / 100];
            res += "Hundred ";
            chunk %= 100;
        }
        if (chunk / 10 > 1) {
            res += ties[chunk / 10];
            res += ones[chunk % 10];
        } else if (chunk / 10 == 1) {
            res += teens[chunk % 10];
        } else {
            res += ones[chunk % 10];
        }
        return res;
    }

public:
    string numberToWords(int num) {
        if (num == 0) return "Zero";
        string words;
        string scaleStrs[] = { "Billion ", "Million ", "Thousand ", "" };
        int s = 1000000000;
        for (auto &scaleStr: scaleStrs) {
            if (num >= s) {
                words += procChunk(num / s) + scaleStr;
                num %= s;
            }
            s /= 1000;
        }
        while (words.back() == ' ')
            words.pop_back();
        return words;
    }
};
