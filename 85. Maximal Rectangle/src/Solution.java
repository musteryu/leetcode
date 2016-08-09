/**
 * Created by musteryu on 16/4/25.
 */
public class Solution {
    public int maximalRectangle(char[][] matrix) {
        if (matrix.length == 0) return 0;
        int row = matrix.length, col = matrix[0].length;
        int[] heights = new int[col];
        int area = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (matrix[i][j] == '1') {
                    heights[j] += 1;
                } else {
                    heights[j] = 0;
                }
            }
            area = Math.max(area, largestRectangleArea(heights));
        }
        return area;
    }

    private int largestRectangleArea(int[] heights) {
        return getMax(heights, 0, heights.length);
    }

    private int getMax(int[] heights, int start, int end) {
        if (start < 0 || start >= end) return 0;
        int minIndex = start;
        int maxArea = 0;
        boolean sorted = true;
        for (int i = start; i < end; i++) {
            if (i > start && heights[i] < heights[i-1]) sorted = false;
            if (heights[i] < heights[minIndex]) minIndex = i;
        }
        if (sorted) {
            for (int i = start; i < end; i++) {
                maxArea = Math.max(maxArea, (end - i) * heights[i]);
            }
            return maxArea;
        }
        return Math.max(
                Math.max(
                        getMax(heights, start, minIndex),
                        getMax(heights, minIndex+1, end)
                ),
                heights[minIndex] * (end - start)
        );
    }

    public static void main(String[] args) {
        char[][] matrix = {
                {'0', '0', '1', '1', '1', '0', '1', '1', '0'},
                {'0', '1', '1', '1', '1', '1', '1', '0', '0'},
                {'0', '0', '1', '1', '1', '1', '1', '1', '1'},
                {'1', '1', '0', '1', '1', '0', '1', '1', '0'},
                {'0', '0', '1', '1', '1', '1', '1', '0', '0'},
                {'0', '0', '0', '0', '1', '1', '0', '0', '0'},
                {'0', '1', '1', '1', '0', '0', '0', '0', '0'},
                {'0', '0', '0', '1', '1', '1', '1', '0', '0'}
        };
        System.out.println(new Solution().maximalRectangle(matrix));
    }
}
