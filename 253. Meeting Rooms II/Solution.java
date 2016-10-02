/**
 * Definition for an interval.
 * public class Interval {
 *     int start;
 *     int end;
 *     Interval() { start = 0; end = 0; }
 *     Interval(int s, int e) { start = s; end = e; }
 * }
 */
public class Solution {
    public int minMeetingRooms(Interval[] intervals) {
        if (intervals == null || intervals.length == 0) return 0;
        Arrays.sort(intervals, new Comparator<Interval>() {
            @Override 
            public int compare(Interval a, Interval b) {
                return a.start - b.start;
            }
        });
        PriorityQueue<Integer> heap = new PriorityQueue<Integer>(
            intervals.length,
            new Comparator<Integer>() {
                @Override
                public int compare(Integer a, Integer b) {
                    return a - b;
                }
            }
        );
        heap.offer(intervals[0].end);
        for (int i = 1; i < intervals.length; ++i) {
            Integer intervalEnd = heap.poll();
            if (intervalEnd <= intervals[i].start) {
                intervalEnd = intervals[i].end;
            } else {
                heap.offer(intervals[i].end);
            }
            heap.offer(intervalEnd);
        }

        return heap.size();
    }
}