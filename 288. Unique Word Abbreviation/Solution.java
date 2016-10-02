public class ValidWordAbbr {
    private HashMap<String, HashSet<String>> abbrs;

    private String getAbbr(String word) {
        int len = word.length();
        if (len <= 2) return word;
        StringBuilder sb = new StringBuilder();
        sb.append(word.charAt(0));
        sb.append(len);
        sb.append(word.charAt(len-1));
        return new String(sb);
    }

    public ValidWordAbbr(String[] dictionary) {
        Objects.requireNonNull(dictionary);
        abbrs = new HashMap<>();
        for (String word: dictionary) {
            String abbr = getAbbr(word);
            if (!abbrs.containsKey(abbr))
                abbrs.put(abbr, new HashSet<>());
            abbrs.get(abbr).add(word);
        }
    }

    public boolean isUnique(String word) {
        Objects.requireNonNull(word);
        String abbr = getAbbr(word);
        if (!abbrs.containsKey(abbr)) return true;
        HashSet<String> set = abbrs.get(abbr);
        if (set.size() == 1 && set.contains(word)) return true;
        return false;
    }
}


// Your ValidWordAbbr object will be instantiated and called as such:
// ValidWordAbbr vwa = new ValidWordAbbr(dictionary);
// vwa.isUnique("Word");
// vwa.isUnique("anotherWord");