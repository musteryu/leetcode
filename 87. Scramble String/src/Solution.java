/**
 * Created by musteryu on 16/4/29.
 */
public class Solution {

    public boolean isScramble(String s1, String s2) {
        if (s1.equals(s2)) return true;
        int[] count = new int[26];
        for (char c: s1.toCharArray()) {
            count[c - 'a']++;
        }
        for (char c: s2.toCharArray()) {
            count[c - 'a']--;
        }
        for (int i: count)
            if (i != 0) return false;
        for (int i = 1; i < s1.length(); i++) {
            if (isScramble(s1.substring(0, i), s2.substring(0, i)) && isScramble(s1.substring(i), s2.substring(i)))
                return true;
            if (isScramble(s1.substring(0, i), s2.substring(s2.length()-i)) &&
                    isScramble(s1.substring(i), s2.substring(0, s2.length()-i)))
                return true;
        }
        return false;
    }

    public static void main(String[] args) {
        String s1 = "abcd", s2 = "cadb";
        System.out.print(new Solution().isScramble(s1, s2));
    }
}
