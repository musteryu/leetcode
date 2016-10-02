public class Solution {
    public int shortestDistance(String[] words, String word1, String word2) {
        int distance = Integer.MAX_VALUE;
        int index1 = -1, index2 = -1;
        for (int i = 0; i < words.length; ++i) {
            if (words[i].equals(word1)) {
                index1 = i;
                if (index2 >= 0) distance = Math.min(distance, index1 - index2);
            } else if (words[i].equals(word2)) {
                index2 = i;
                if (index1 >= 0) distance = Math.min(distance, index2 - index1);
            }
            if (distance == 1) return distance;
        }
        return distance;
    }
}