/**
 * Definition for a point.
 * class Point {
 *     int x;
 *     int y;
 *     Point() { x = 0; y = 0; }
 *     Point(int a, int b) { x = a; y = b; }
 * }
 */
public class Solution {
    public int maxPoints(Point[] points) {
        int maxNum = 0;
        Arrays.sort(points, new Comparator<Point>() {
            @Override
            public int compare(Point a, Point b) {
                if (a.x < b.x) return -1;
                if (a.x > b.x) return 1;
                if (a.y < b.y) return -1;
                if (a.y > b.y) return 1;
                return 0;
            }
        });
        for (int i = 0; i < points.length; ++i) {
            maxNum = Math.max(maxNum, find(points, points[i]));
        }
        return maxNum;
    }

    private double slop(Point a, Point b) {
        if (a.x == b.x && a.y == b.y) return Double.NEGATIVE_INFINITY;
        if (a.x == b.x) return -Double.MAX_VALUE;
        return ((double) (a.y - b.y)) / (a.x - b.x);
    }

    private int find(Point[] points, Point origin) {
        int maxNum = 0;
        double[] slops = new double[points.length];
        for (int i = 0; i < slops.length; ++i)
            slops[i] = slop(points[i], origin);
        Arrays.sort(slops);
        int slow = 0;
        while (slow < slops.length && slops[slow] == Double.NEGATIVE_INFINITY) 
            slow++;
        if (slow == slops.length) return slow;
        int start = slow, fast = slow+1;
        while (fast < slops.length) {
            if (slops[fast] != slops[fast-1]) {
                maxNum = Math.max(maxNum, fast - slow + start);
                slow = fast; 
            }
            ++fast;
        }
        maxNum = Math.max(maxNum, fast - slow + start);
        return maxNum;
    }
}