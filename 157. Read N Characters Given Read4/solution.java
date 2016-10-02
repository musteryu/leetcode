/* The read4 API is defined in the parent class Reader4.
      int read4(char[] buf); */

public class Solution extends Reader4 {
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    public int read(char[] buf, int n) {
        int bufTop = 0;
        char[] buf4 = new char[4];
        while (n > 0) {
            int counts = read4(buf4);
            for (int i = 0; i < Math.min(counts, n); ++i) {
                buf[bufTop++] = buf4[i];
            }
            if (counts == 0) break;
            n -= counts;
        }
        return bufTop;
    }
}