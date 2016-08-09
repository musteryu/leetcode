import java.util.ArrayList;
import java.util.List;

/**
 * Created by musteryu on 16/4/30.
 */
public class Solution {
    public List<Integer> grayCode(int n) {
        List<Integer> grayCodes = new ArrayList<>();
        for (int i = 0; i < Math.pow(2, n); i++)
            grayCodes.add(bin2Gray(i, n));
        return grayCodes;
    }

    private int bin2Gray(int bin, int digits) {
        int gray = 0;
        while (digits > -1) {
            gray |= (bin ^ (bin >> 1)) & (1 << digits);
            digits--;
        }
        return gray;
    }

    public static void main(String[] args) {
        ArrayList<Integer> grayCodes = (ArrayList<Integer>) new Solution().grayCode(0);
        for (Integer i: grayCodes) {
            System.out.println(String.format("%4s", Integer.toBinaryString(i)));
        }
    }
}
