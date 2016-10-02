public class Solution {
  public boolean verifyPreorder(int[] preorder) {
    if (preorder.length < 3) return true;
    int max = 0, min = -1;
    for (int i = 1; i < preorder.length; ++i) {
      int curr = preorder[i];
      if (min != -1 && curr < preorder[min]) return false;
      if (curr > preorder[max]) {
        min = max;
        max = i;
      } else if (curr > preorder[i-1]) {
        if (min == -1) min = i - 1;
        while (min - 1 >= 0 && preorder[min - 1] < curr)
          min--;
      }
    }
    return true;
  }
}