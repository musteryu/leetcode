public class Solution {
  public List<List<Integer>> getFactors(int n) {
    List<List<Integer>> ret = new ArrayList<>();
    addFactors(n, 2, ret);
    return ret;
  }

  private static void addFactors(int n, int base, List<List<Integer>> result) {
    for(int i = base; i * i <= n; i++) {
      if(n % i == 0) {
        int updated = result.size();
        addFactors(n / i, i, result);
        List<Integer> factors = new ArrayList<>();
        result.add(factors);
        factors.add(n / i);
        while(updated < result.size()) result.get(updated++).add(i);
      }
    }
  }
}