public class Solution {
    private void helper(HashMap<Character, Integer> countOf, 
            char[] charArray, int currIndex, List<String> results) {
        if (currIndex < 0) {
            results.add(new String(charArray));
            return;
        }
        for (Character c: countOf.keySet()) {
            int count = countOf.get(c);
            if (count == 0) continue;
            countOf.put(c, count - 2);
            charArray[currIndex] = c;
            charArray[charArray.length - 1 - currIndex] = c;
            helper(countOf, charArray, currIndex-1, results);
            countOf.put(c, count);
        }
    }

    public List<String> generatePalindromes(String s) {
        int sLen = s.length();
        char[] charArray = new char[sLen];
        HashMap<Character, Integer> countOf = new HashMap<>();
        List<String> results = new ArrayList<>();
        for (int i = 0; i < sLen; i++) {
            char c = s.charAt(i);
            if (countOf.containsKey(c))
                countOf.put(c, countOf.get(c) + 1);
            else
                countOf.put(c, 1);
        }

        Character oddChar = null;
        for (Character c: countOf.keySet()) {
            if (countOf.get(c) % 2 == 1) {
                if (oddChar != null) return results;
                oddChar = c;
            }
        }

        if (sLen % 2 == 1) {
            charArray[sLen / 2] = oddChar;
            countOf.put(oddChar, countOf.get(oddChar) - 1);
        }
        helper(countOf, charArray, sLen / 2 - 1, results);
        return results;
    }
}