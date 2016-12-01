public class Solution {
    public int superPow(int a, int[] b) {
        return superPow(a, b, b.length-1);
    }

    private int powMod(int a, int k) {
        a %= 1337;
        int res = 1;
        for (int i = 0; i < k; ++i)
            res = (res * a) % 1337;
        return res;
    }

    private int superPow(int a, int[] b, int bTopIndex) {
        if (bTopIndex == -1) return 1;
        int bTop = b[bTopIndex--];
        return powMod(superPow(a, b, bTopIndex), 10) * powMod(a, bTop) % 1337;
    }
}