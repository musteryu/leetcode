public class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> res = new LinkedList<Integer>();
        int m = matrix.length;
        if (m == 0) return res;
        int n = matrix[0].length;
        if (n == 0) return res;
        int lowerI = 0, upperI = m - 1, lowerJ = 0, upperJ = n - 1;
        
        while (lowerI < upperI && lowerJ < upperJ) {
            int i = lowerI, j = lowerJ;
            for (j = lowerJ; j < upperJ; ++j)
                res.add(matrix[i][j]);
            for (i = lowerI; i < upperI; ++i)
                res.add(matrix[i][j]);
            for (j = upperJ; j > lowerJ; --j)
                res.add(matrix[i][j]);
            for (i = upperI; i > lowerI; --i)
                res.add(matrix[i][j]);
            ++lowerI;
            ++lowerJ;
            --upperI;
            --upperJ;
        }
        if (lowerI != upperI && lowerJ == upperJ)
            for (int i = lowerI; i <= upperI; ++i)
                res.add(matrix[i][lowerJ]);
        else if (lowerJ != upperJ && lowerI == upperI)
            for (int j = lowerJ; j <= upperJ; ++j)
                res.add(matrix[lowerI][j]);
        else if (lowerI == upperI && lowerJ == upperJ)
            res.add(matrix[lowerI][lowerJ]);
        return res;
    }
}