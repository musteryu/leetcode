/**
 * Created by musteryu on 16/4/30.
 */
public class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        for (int i1 = m - 1, i2 = n - 1, i = m + n - 1; i > -1; i--) {
            if (i2 < 0 || i1 >= 0 && nums1[i1] > nums2[i2]) {
                nums1[i] = nums1[i1--];
            } else {
                nums1[i] = nums2[i2--];
            }
        }
    }

    public static void main(String[] args) {
        int[] nums1 = new int[10];
        for (int i = 0; i != 5; i++) {
            nums1[i] = 3;
        }
        int[] nums2 = {1, 1, 1, 1, 1};

        new Solution().merge(nums1, 5, nums2, 5);
        for (int i: nums1) {
            System.out.print(i + " ");
        }
    }
}
