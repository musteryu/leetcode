public class Solution {
    private boolean isMatch(String pattern, int pi, String str, int si,
                            Map<Character, String> map, Set<String> set) {
        if (pi == pattern.length() && si == str.length()) return true;
        if (pi == pattern.length() || si == str.length()) return false;
        char c = pattern.charAt(pi);
        if (map.containsKey(c)) {
            String s = map.get(c);
            if (!str.startsWith(s, si)) return false;
            return isMatch(pattern, pi + 1, str, si + s.length(), map, set);
        } else {
            for (int k = si + 1; k <= str.length(); ++k) {
                String p = str.substring(si, k);
                if (set.contains(p)) continue;
                map.put(c, p);
                set.add(p);
                if (isMatch(pattern, pi + 1, str, k, map, set))
                    return true;
                map.remove(c);
                set.remove(p);
            }
        }
        return false;
    }
    public boolean wordPatternMatch(String pattern, String str) {
        Map<Character, String> map = new HashMap<>();
        Set<String> set = new HashSet<>();
        return isMatch(pattern, 0, str, 0, map, set);
    }
}