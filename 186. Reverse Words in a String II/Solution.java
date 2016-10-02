import java.util.Collections;

public class Solution {
    private void swap(char[] s, int i, int j) {
        char tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
    }

    private void reverseWords(char[] s, int begin, int end) {
        while (begin < end) {
            swap(s, begin++, --end);
        }
    }

    public void reverseWords(char[] s) {
        int begin = 0;
        for (int end = 1; end <= s.length; ++end) {
            if (end == s.length || s[end] == ' ') {
                reverseWords(s, begin, end);
                begin = ++end;
            }
        }
        reverseWords(s, 0, s.length);
    }
}