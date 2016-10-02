public class Solution {
    public int shortestWordDistance(String[] words, String word1, String word2) {
        if (word1.equals(word2)) {
            int last = -1, distance = Integer.MAX_VALUE;
            for (int curr = 0; curr < words.length; ++curr) {
                if (words[curr].equals(word1)) {
                    if (last >= 0) 
                        distance = Math.min(distance, curr - last);
                    last = curr;
                }
            }
            return distance;
        } else {
            int index1 = -1, index2 = -1, distance = Integer.MAX_VALUE;
            for (int i = 0; i < words.length; ++i) {
                if (words[i].equals(word1)) {
                    index1 = i;
                    if (index2 >= 0) 
                        distance = Math.min(distance, index1 - index2);
                } else if (words[i].equals(word2)) {
                    index2 = i;
                    if (index1 >= 0)
                        distance = Math.min(distance, index2 - index1);
                }
            }
            return distance;
        }
    }
}