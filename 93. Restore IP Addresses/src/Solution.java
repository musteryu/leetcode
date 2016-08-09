import java.util.ArrayList;
import java.util.List;

/**
 * Created by musteryu on 16/5/1.
 */
public class Solution {
    public List<String> restoreIpAddresses(String s) {
        List<String> addresses = new ArrayList<>();
        if (s.length() > 12) return addresses;
        for (int i = 1; i < s.length() - 2; i++) {
            for (int j = i+1; j < s.length() - 1; j++) {
                for (int k = j+1; k < s.length(); k++) {
                    String s1 = s.substring(0, i);
                    String s2 = s.substring(i, j);
                    String s3 = s.substring(j, k);
                    String s4 = s.substring(k);
                    if (check(s1) && check(s2) && check(s3) && check(s4)) {
                        addresses.add(
                                s1 + "." + s2 + "." + s3 + "." + s4
                        );
                    }
                }
            }
        }
        return addresses;
    }

    private boolean check(String s) {
        if (s.length() > 3) return false;
        int i = Integer.parseInt(s);
        if (s.charAt(0) == '0') {
            return s.length() == 1;
        } else if (i < 256) {
            return true;
        } else return false;
    }

    public static void main(String[] args) {
        ArrayList<String> addr = (ArrayList) new Solution().restoreIpAddresses("0000");
        CollectionUtil.printIterable(addr, "\n");
    }
}
