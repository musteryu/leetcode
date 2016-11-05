public class Solution {
    public int lengthLongestPath(String input) {
        String[] files = input.split("\n");
        Stack<String> stack = new Stack<String>();
        int level = -1;
        int length = 0;
        int maxLength = 0;
        for (String file: files) {
            int i = 0;
            boolean isFile = false;
            while (file.charAt(i) == '\t') ++i;
            for (int j = i; j < file.length(); ++j)
                isFile = isFile || (file.charAt(j) == '.');
            if (i > 0) file = file.substring(i);
            if (i > level) {
                ++level;      
            } else {
                for (; level >= i; --level)
                    length -= stack.pop().length();
                ++level;
            }
            stack.push(file);
            length += file.length();
            if (level >= 0 && isFile) 
                maxLength = Math.max(maxLength, length + stack.size() - 1);
        }
        return maxLength;
    }
}