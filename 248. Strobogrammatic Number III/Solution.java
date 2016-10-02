public class Solution {
    private char[][] pairs = {
        {'0', '0'}, {'1', '1'}, {'6', '9'}, {'8', '8'}, {'9', '6'}
    };

    private int partialCount(String low, String high, char[] chars, 
            int left, int right) {
        if (left > right) {
            String stro = new String(chars);
            if (low.length() == chars.length && low.compareTo(stro) > 0 
            || high.length() == chars.length && high.compareTo(stro) < 0) return 0;
            else return 1;
        } else {
            int count = 0;
            for (char[] pair: pairs) {
                if (left == right && pair[0] != pair[1]) continue;
                chars[left] = pair[0];
                chars[right] = pair[1];
                if (chars.length != 1 && chars[0] == '0') continue;
                count += partialCount(low, high, chars, left+1, right-1);
            }
            return count;
        }
    }

    public int strobogrammaticInRange(String low, String high) {
        int count = 0;
        for (int len = low.length(); len <= high.length(); ++len) {
            count += partialCount(low, high, new char[len], 0, len-1);
        }
        return count;
    }
}