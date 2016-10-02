public class Solution {
    public boolean isOneEditDistance(String s, String t) {
        int sLen = s.length(), tLen = t.length();
        int sIndex, tIndex;
        int diffCount = 0;
        for (sIndex = 0, tIndex = 0;
            sIndex < sLen && tIndex < tLen; ++sIndex, ++tIndex) {
            if (s.charAt(sIndex) != t.charAt(tIndex)) {
                if (sLen - sIndex > tLen - tIndex) --tIndex;
                else if (sLen - sIndex < tLen - tIndex) --sIndex;
                if (++diffCount > 1) return false;
            }
        }
        return diffCount + Math.max(sLen - sIndex, tLen - tIndex) == 1;
    }
}