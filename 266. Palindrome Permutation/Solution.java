public class Solution {
    public boolean canPermutePalindrome(String s) {
        int[] count = new int[256];
        for (int i = 0; i < s.length(); ++i) {
            ++count[s.charAt(i)];
        }
        int oddCount = 0;
        for (int cnt: count) {
            if (cnt % 2 == 1) {
                if (++oddCount > 1) return false;
            }
        }
        return true;
    }
}