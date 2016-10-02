public class Solution {
    private int firstMissNumber(Set<Integer> set) {
        int size = set.size();
        for (int i = 0; i < size; ++i) {
            if (!set.contains(i)) return i;
        }
        return size;
    }

    public boolean canWin(String s) {
        int maxLen = 0;
        int currLen = 0;
        List<Integer> boardInitState = new ArrayList<Integer>();
        for (int i = 0; i < s.length(); ++i) {
            if (s.charAt(i) == '+') currLen++;
            if (i == s.length() - 1 || s.charAt(i) == '-') {
                if (currLen >= 2) boardInitState.add(currLen);
                maxLen = Math.max(maxLen, currLen);
                currLen = 0;
            }
        }
        int[] g = new int[maxLen+1];
        for (int len = 2; len <= maxLen; ++len) {
            Set<Integer> gSub = new HashSet<Integer>();
            for (int first = 0; first < len / 2; ++first) {
                int second = len - first - 2;
                gSub.add(g[first] ^ g[second]);
            }
            g[len] = firstMissNumber(gSub);
        }
        int gFinal = 0;
        for (Integer subState: boardInitState)
            gFinal ^= g[subState];
        return gFinal != 0;
    }
}