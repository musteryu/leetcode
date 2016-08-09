/**
 * Created by musteryu on 16/4/30.
 */
public class Solution {
    public int numDecodings(String s) {
        if (s.length() == 0 || s.charAt(0) == '0') return 0;
        int last = 1, curr = 1, tmp, n;
        for (int i = 1; i < s.length(); i++) {
            n = (s.charAt(i-1) - '0') * 10 + (s.charAt(i) - '0');
            if (s.charAt(i) == '0') {
                if (n == 0) {
                    return 0;
                } else if (n > 26) {
                    return 0;
                } else {
                    tmp = curr;
                    curr = last;
                    last = tmp;
                }
            } else if (n < 10 || n > 26) {
                curr = curr;
                last = curr;
            } else {
                curr = last + curr;
                last = curr - last;
            }
        }
        return curr;
    }

    public static void main(String[] args) {
        System.out.print(new Solution().numDecodings("12122021"));
    }
}
