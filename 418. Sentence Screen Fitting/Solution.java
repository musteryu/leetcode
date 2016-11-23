public class Solution {
    public int wordsTyping(String[] sentence, int rows, int cols) {
        int r = 0, c = 0, count = 0, len = 0, s = 0;
        for (String word: sentence)
            len += word.length() + 1;
        while (r < rows) {
            if (cols - c > len && s == 0) {
                count += (cols - c) / len;
                c += (cols - c) / len * len; 
            }
            if (cols - c < sentence[s].length()) {
                ++r;
                c = 0;
            } else if (cols - c > sentence[s].length) {
                c += sentence[s++].length() + 1;
            } else {
                c += sentence[s++].length();
            }
        }
    }
}