public class Solution {
    public String decodeString(String s) {
        Stack<Integer> repeats = new Stack<>();
        Stack<StringBuilder> strs = new Stack<>();
        repeats.push(1);
        strs.push(new StringBuilder());
        int times = 0;
        for (int i = 0; i < s.length(); ++i) {
            char c = s.charAt(i);
            if (c >= '0' && c <= '9') {
                while (c != '[') {
                    times = times * 10 + c - '0';
                    c = s.charAt(++i);
                }
                repeats.push(times);
                strs.push(new StringBuilder());
                times = 0;
            } else if (c == ']') {
                StringBuilder top = strs.pop();
                StringBuilder base = strs.peek();
                int rp = repeats.pop();
                for (int j = 0; j < rp; ++j)
                    base.append(top.toString());
            } else {
                strs.peek().append(c);
            }
        }
        return strs.peek().toString();
    }
}