public class Codec {

    // Encodes a list of strings to a single string.
    public String encode(List<String> strs) {
        StringBuilder sb = new StringBuilder();
        for (String str: strs) {
            sb.append("$");
            sb.append(str.length());
            sb.append("$");
            sb.append(str);
        }
        return new String(sb);
    }

    // Decodes a single string to a list of strings.
    public List<String> decode(String s) {
        LinkedList<String> list = new LinkedList<String>();
        for (int i = 0; i < s.length(); /**/) {
            if (s.charAt(i) == '$') {
                int j = i + 1;
                for (; j < s.length() && s.charAt(j) != '$'; ++j)
                    /* do nothing */;
                int len = Integer.parseInt(s.substring(i+1, j));
                list.add(s.substring(j+1, j+1+len));
                i = j + 1 + len;
            } else ++i; /* should not go here if correctly formatted. */
        }
        return list;
    }
}

// Your Codec object will be instantiated and called as such:
// Codec codec = new Codec();
// codec.decode(codec.encode(strs));