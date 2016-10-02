public class Solution {
    private boolean isStrobogrammatic(char a, char b) {
        if (a == b) {
            return a == '0' || a == '1' || a == '8';
        } else {
            return a == '6' && b == '9' || a == '9' && b == '6';
        }
    }

    public boolean isStrobogrammatic(String num) {
        int l = 0, r = num.length() - 1;
        while (l <= r) {
            if (!isStrobogrammatic(num.charAt(l++), num.charAt(r--)))
                return false;
        } 
        return true;
    }
}