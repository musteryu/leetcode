public class Solution {
    public List<int[]> kSmallestPairs(int[] nums1, int[] nums2, int k) {
        PriorityQueue<Pair> hp = new PriorityQueue<Pair>();
        List<int[]> res = new LinkedList<int[]>();
        if (nums1 == null || nums1.length == 0 ||
            nums2 == null || nums2.length == 0)
            return res;
        for (int j = 0; j < nums2.length; ++j)
            hp.offer(new Pair(0, j, nums1[0] + nums2[j]));
        for (int i = 0; i < Math.min(k, nums1.length * nums2.length); ++i) {
            Pair t = hp.poll();
            res.add(t.toPair(nums1, nums2));
            if (t.i == nums1.length - 1) continue;
            hp.offer(new Pair(t.i + 1, t.j, nums1[t.i+1] + nums2[t.j]));
        }
        return res;
    }

    private static class Pair implements Comparable<Pair> {
        private int i, j, val;
        public Pair(int i, int j, int val) {
            this.i = i;
            this.j = j;
            this.val = val;
        }

        public int[] toPair(int[] arr1, int[] arr2) {
            return new int[] {arr1[i], arr2[j]};
        }

        @Override
        public int compareTo(Pair that) {
            return this.val - that.val;
        }
    }
}