public class Solution {
    public int divide(int dividend, int divisor) {
        if (dividend == Integer.MIN_VALUE && divisor == -1) return Integer.MAX_VALUE;
        if (dividend > 0 && divisor > 0) return divideHelper(-dividend, -divisor);
        else if (dividend > 0) return -divideHelper(-dividend,divisor);
        else if (divisor > 0) return -divideHelper(dividend,-divisor);
        else return divideHelper(dividend, divisor);
    }

    private int divideHelper(int dividend, int divisor) {
        if (divisor < dividend) return 0;
        int divideResult = 0;
        int result = 1;
        int multiDivisor = divisor;
        int shiftCount = 0;
        while (dividend < multiDivisor && (multiDivisor << 1) < 0 && shiftCount < 30) {
            multiDivisor <<= 1;
            result <<= 1;
            shiftCount ++;
        }
        while (dividend <= divisor) {
            while (dividend > multiDivisor) {
                multiDivisor >>= 1;
                result >>= 1;
            }
            divideResult += result;
            dividend -= multiDivisor;
        }
        return divideResult;
    }
}