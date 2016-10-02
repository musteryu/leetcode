public class TwoSum {
    private HashMap<Integer, Integer> counts;
    private LinkedList<Integer> keys;

    public TwoSum() {
        counts = new HashMap<>();
        keys = new LinkedList<>();
    }

    // Add the number to an internal data structure.
    public void add(int number) {
        if (counts.containsKey(number)) {
            counts.put(number, counts.get(number) + 1);
        } else {
            keys.add(number);
            counts.put(number, 1);
        }
    }

    // Find if there exists any pair of numbers which sum is equal to the value.
    public boolean find(int value) {
        for (Integer num1: keys) {
            int num2 = value - num1;
            if (num1 == num2 && counts.get(num1) > 1 ||
                num1 != num2 && counts.containsKey(num2))
                return true;
        }
        return false;
    }
}


// Your TwoSum object will be instantiated and called as such:
// TwoSum twoSum = new TwoSum();
// twoSum.add(number);
// twoSum.find(value);