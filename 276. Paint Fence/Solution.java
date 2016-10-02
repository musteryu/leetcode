public class Solution {
    public int numWays(int n, int k) {
        if (n == 0 || k == 0) return 0;
        int same = 0, diff = k;
        while (--n > 0) {
            int lastSame = same;
            same = diff;
            diff = (diff + lastSame) * (k-1);
        }
        return same + diff;
    }
}