public class Solution {
    public int getMoneyAmount(int n) {
        int[][] money = new int[n+1][n+1];
        return getMoneyAmount(1, n, money);
    }

    private int getMoneyAmount(int min, int max, int[][] money) {
        if (min >= max) return 0;
        if (money[min][max] == 0) {
            int minMoney = Integer.MAX_VALUE;
            for (int i = min; i <= max; ++i) {
                minMoney = Math.min(
                    minMoney,
                    Math.max(
                        getMoneyAmount(min, i-1, money) + i,
                        i + getMoneyAmount(i+1, max, money)
                    )
                );
            }
            money[min][max] = minMoney;
        }
        return money[min][max];
    }
}