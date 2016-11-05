public class Solution {
    public int getSum(int a, int b) {
        int bit = 1;
        int sum = 0;
        int carry = 0;
        for (int i = 0; i < 32; ++i, bit <<=1) {
            sum |= (carry ^ a ^ b) & bit;
            carry = (a & b | a & carry | b & carry) << 1;
        }
        return sum;
    }
}