/**
 * Created by musteryu on 16/5/2.
 */
public class Solution {
    public boolean isInterleave(String s1, String s2, String s3) {
        if (s1.length() + s2.length() != s3.length()) return false;
        if (s1.length() == 0) return s2.equals(s3);
        if (s2.length() == 0) return s1.equals(s3);
        boolean[][] path = new boolean[s1.length()+1][s2.length()+2];
        path[0][0] = true;
        for (int i = 0; i < s1.length(); i++) {
            path[i+1][0] = path[i][0] && s1.charAt(i) == s3.charAt(i);
        }
        for (int j = 0; j < s2.length(); j++) {
            path[0][j+1] = path[0][j] && s2.charAt(j) == s3.charAt(j);
        }

        for (int i = 0; i < s1.length(); i++) {
            for (int j = 0; j < s2.length(); j++) {
                path[i+1][j+1] = (path[i][j+1] && s1.charAt(i) == s3.charAt(i+j+1)) ||
                        (path[i+1][j] && s2.charAt(j) == s3.charAt(i+j+1));
            }
        }
        return path[s1.length()][s2.length()];
    }

    public static void main(String[] args) {
        System.out.println(new Solution().isInterleave(
                "aabcc",
                "dbbca",
                "aadbbcbcac"
        ));
    }
}
