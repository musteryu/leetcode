public class Solution {
    public int wiggleMaxLength(int[] nums) {
        if (nums == null || nums.length == 0) return 0;
        int[] stack1 = new int[nums.length]; // for 1 2 1 2 1
        int[] stack2 = new int[nums.length]; // for 2 1 2 1 2
        int top1 = 1;
        int top2 = 1;
        stack2[0] = stack1[0] = nums[0];
        for (int i = 1; i < nums.length; ++i) {
            int num = nums[i];
            if (top1 % 2 == 0) {
                if (num < stack1[top1-1])
                    stack1[top1++] = num;
                else stack1[top1-1] = num;
            } else {
                if (num > stack1[top1-1])
                    stack1[top1++] = num;
                else stack1[top1-1] = num;
            }
            if (top2 % 2 == 0) {
                if (num > stack2[top2-1])
                    stack2[top2++] = num;
                else stack2[top2-1] = num;
            } else {
                if (num < stack2[top2-1])
                    stack2[top2++] = num;
                else stack2[top2-1] = num;
            }
        }
        return Math.max(top1, top2);
    }
}