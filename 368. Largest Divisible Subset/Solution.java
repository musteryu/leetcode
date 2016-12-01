public class Solution {
    public List<Integer> largestDivisibleSubset(int[] nums) {
        List<Integer> subset = new LinkedList<Integer>();
        if (nums.length == 0) return subset;
        Arrays.sort(nums);
        int[] size = new int[nums.length];
        int[] last = new int[nums.length];
        for (int i = 1; i < nums.length; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] % nums[j] == 0) {
                    if (size[j] + 1 > size[i]) {
                        size[i] = size[j] + 1;
                        last[i] = j + 1;
                    }
                }
            }
        }
        int maxSize = 0;
        int maxIndex = 0;
        for (int i = 1; i < nums.length; ++i) {
            if (size[i] > size[maxIndex]) {
                maxSize = size[i];
                maxIndex = i;
            }
        }
        do {
            subset.add(nums[maxIndex]);
            maxIndex = last[maxIndex] - 1;
        } while (maxIndex >= 0);
        return subset;
    }
}