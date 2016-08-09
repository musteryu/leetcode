import java.util.Map;

/**
 * Created by musteryu on 16/4/25.
 */
public class Solution {
    public int largestRectangleArea(int[] heights) {
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
        int[] height = new int[1000];
        for (int i = 0; i < height.length; i++) {
            height[i] = 1;
        }
        System.out.println(new Solution().largestRectangleArea(height));
    }
}
