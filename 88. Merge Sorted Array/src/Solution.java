/**
 * Created by musteryu on 16/4/30.
 */
public class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        for (int mn = m-- + --n; mn > -1; --mn) {
            if (m > -1 && (n < 0 || nums1[m] > nums2[n]))
                nums1[mn] = nums1[m--];
            else
                nums1[mn] = nums2[n--];
        }
    }
}
