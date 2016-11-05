public class Solution {
    private int[] nums;
    private Random rand;

    public Solution(int[] nums_) {
        nums = nums_;
        rand = new Random();
    }
    
    /** Resets the array to its original configuration and return it. */
    public int[] reset() {
        return this.nums;
    }
    
    /** Returns a random shuffling of the array. */
    public int[] shuffle() {
        int[] newNums = Arrays.copyOf(nums, nums.length);
        int a = 0, b = 0;
        while (a == b) {
            a = rand.nextInt();
            b = rand.nextInt();
        }
        int tmp = newNums[a];
        newNums[a] = newNums[b];
        newNums[b] = tmp;
        return newNums;
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int[] param_1 = obj.reset();
 * int[] param_2 = obj.shuffle();
 */