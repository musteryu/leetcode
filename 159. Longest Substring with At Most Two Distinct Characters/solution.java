public class Solution {
    public int lengthOfLongestSubstringTwoDistinct(String s) {
        int length = 0;
        int[] charCounts = new int[Character.MAX_VALUE];
        int chars = 0;
        int slow, fast;
        for (slow = 0, fast = 0; fast < s.length(); ++fast) {
            char c = s.charAt(fast);
            if (charCounts[c]++ == 0)
                chars++;
            if (chars > 2) {
                length = Math.max(length, fast-slow);
                while (chars > 2) {
                    if (--charCounts[s.charAt(slow++)] == 0)
                        chars--;
                }
            }
        }
        if (chars <= 2) length = Math.max(length, fast - slow);
        return length;
    }
}