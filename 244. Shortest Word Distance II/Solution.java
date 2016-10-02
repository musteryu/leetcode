public class WordDistance {
    HashMap<String, List<Integer>> indicesOf;

    public WordDistance(String[] words) {
        indicesOf = new HashMap<>();     
        int i = 0;
        for (String word: words) {
            if (!indicesOf.containsKey(word))
                indicesOf.put(word, new ArrayList<Integer>());
            indicesOf.get(word).add(i++);
        }
    }

    public int shortest(String word1, String word2) {
        List<Integer> indices1 = indicesOf.get(word1);
        List<Integer> indices2 = indicesOf.get(word2);
        int it1 = 0, it2 = 0, distance = Integer.MAX_VALUE;
        while (it1 < indices1.size() && it2 < indices2.size()) {
            int index1 = indices1.get(it1);
            int index2 = indices2.get(it2);
            distance = Math.min(distance, Math.abs(index1 - index2));
            if (index1 < index2) {
                ++it1;
            } else ++it2;
        }
        return distance;
    }
}

// Your WordDistance object will be instantiated and called as such:
// WordDistance wordDistance = new WordDistance(words);
// wordDistance.shortest("word1", "word2");
// wordDistance.shortest("anotherWord1", "anotherWord2");