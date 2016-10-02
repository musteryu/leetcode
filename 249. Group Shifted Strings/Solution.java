public class Solution {
    private String patternOf(String string) {
        char base = string.charAt(0);
        char[] patternChars = new char[string.length()];
        for (int i = 0; i < string.length(); ++i) {
            patternChars[i] = (char) ((string.charAt(i) - base + 26) % 26 + 'a');
        }
        return new String(patternChars);
    }

    public List<List<String>> groupStrings(String[] strings) {
        HashMap<String, List<String>> patterns = new HashMap<>();
        List<List<String>> groups = new LinkedList<>();
        for (String string: strings) {
            String pattern = patternOf(string);
            if (!patterns.containsKey(pattern)) {
                List<String> newGroup = new LinkedList<>();
                patterns.put(pattern, newGroup);
                groups.add(newGroup);
            }
            patterns.get(pattern).add(string);
        }
        for (String pattern: patterns.keySet()) {
            patterns.put(pattern, null);
        }
        return groups;
    }
}