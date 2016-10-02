public class Solution {
    public List<String> findStrobogrammatic(int n) {
        return findStrobogrammatic(n, true);
    }

    private List<String> findStrobogrammatic(int n, boolean outestFlag) {
        if (n == 0) {
            return new ArrayList<String>() {{ add(""); }};
        } else if (n == 1) {
            return new ArrayList<String>(Arrays.asList("0", "1", "8"));
        } else {
            List<String> subResults = findStrobogrammatic(n - 2, false);
            List<String> results = new ArrayList<String>();
            for (String subResult: subResults) {
                if (!outestFlag)
                    results.add("0" + subResult + "0");
                results.add("1" + subResult + "1");
                results.add("6" + subResult + "9");
                results.add("8" + subResult + "8");
                results.add("9" + subResult + "6");
            }
            return results;
        } 
    }
}