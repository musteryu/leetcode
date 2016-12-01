public class Solution {
    public int[] getModifiedArray(int length, int[][] updates) {
        int[] incr = new int[length];
        for (int[] u: updates) {
            incr[u[0]] += u[2];
            if (u[1] < length - 1)
                incr[u[1] + 1] -= u[2];
        }
        int curr = 0;
        for (int i = 0; i < length; ++i) {
            curr += incr[i];
            incr[i] = curr;
        }
        return incr;
    }
}