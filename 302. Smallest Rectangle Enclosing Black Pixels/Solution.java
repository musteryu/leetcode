public class Solution {
    private boolean isWhite(char[][] image, int k, int mid, boolean rowWise) {
        return (rowWise ? image[k][mid] : image[mid][k]) == '0';
    }

    private int bound(char[][] image, int i, int j, int low, int high, 
                        boolean rowWise, boolean opt) {
        while (i != j) {
            int k = low;
            int mid = (i + j) / 2;
            while (k < high && isWhite(image, k, mid, rowWise)) 
                ++k;
            if (k < high == opt)
                j = mid;
            else
                i = mid + 1;
        }
        return i;
        
    }

    public int minArea(char[][] image, int x, int y) {
        int rows = image.length;
        int cols = image[0].length;
        int rowLower = bound(image, 0, y, 0, rows, true, true);
        int rowUpper = bound(image, y, cols, 0, rows, true, false);
        int colLower = bound(image, 0, x, rowLower, rowUpper, false, true);
        int colUpper = bound(image, x, rows, rowLower, rowUpper, false, false);
        return (rowUpper - rowLower) * (colUpper - colLower);
    }
}