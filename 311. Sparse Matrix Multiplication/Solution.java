public class Solution {
    public int[][] multiply(int[][] A, int[][] B) {
        int Am = A.length, Bm = B.length;
        int An = A[0].length, Bn = B[0].length;
        @SuppressWarnings("unchecked")
        ArrayList<Pair>[] Arows = new ArrayList[Am];
        @SuppressWarnings("unchecked")
        ArrayList<Pair>[] Bcols = new ArrayList[Bn];
        int[][] C = new int[Am][Bn];
        for (int i = 0; i < Am; ++i) {
            Arows[i] = new ArrayList<Pair>();
            for (int j = 0; j < An; ++j) {
                if (A[i][j] != 0)
                    Arows[i].add(new Pair(j, A[i][j]));
            }
        }
        for (int j = 0; j < Bn; ++j) {
            Bcols[j] = new ArrayList<Pair>();
            for (int i = 0; i < Bm; ++i) {
                if (B[i][j] != 0)
                    Bcols[j].add(new Pair(i, B[i][j]));
            }
        }
        for (int i = 0; i < Am; ++i) {
            for (int j = 0; j < Bn; ++j) {
                C[i][j] = multi(Arows[i], Bcols[j]);
            }
        }
        return C;
    }

    private int multi(ArrayList<Pair> a, ArrayList<Pair> b) {
        int product = 0;
        if (a != null && b != null) {
            for (int ai = 0, bi = 0; ai < a.size() && bi < b.size(); ++ai, ++bi) {
                Pair ap = a.get(ai), bp = b.get(bi);
                if (ap.index == bp.index) 
                    product += ap.value * bp.value;
                else if (ap.index < bp.index)
                    --bi;
                else
                    --ai;
            }
        }
        return product;
    }
}

class Pair {
    public int index;
    public int value;
    public Pair(int index_, int value_) {
        index = index_;
        value = value_;
    }
}