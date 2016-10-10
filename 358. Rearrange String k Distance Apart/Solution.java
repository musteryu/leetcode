public class Solution {
    public String rearrangeString(String str, int k) {
        StringBuilder sb = new StringBuilder();
        Map<Character, Integer> map = new HashMap<Character, Integer>();
        for (char c: str.toCharArray()) {
            if (!map.containsKey(c))
                map.put(c, 1);
            else map.put(c, map.get(c) + 1); 
        }
        Queue<Map.Entry<Character, Integer>> maxHeap = new PriorityQueue<Map.Entry<Character, Integer>>(
            new Comparator<Map.Entry<Character, Integer>>() {
                @Override
                public int compare(Map.Entry<Character, Integer> a, Map.Entry<Character, Integer> b) {
                    return b.getValue() - a.getValue();
                }
            }
        );
        Queue<Map.Entry<Character, Integer>> waitQueue = new LinkedList<>();
        maxHeap.addAll(map.entrySet());
        while (!maxHeap.isEmpty()) {
            Map.Entry<Character, Integer> current = maxHeap.poll();
            sb.append(current.getKey());
            current.setValue(current.getValue()-1);
            waitQueue.offer(current);
            if (waitQueue.size() < k) continue;
            Map.Entry<Character, Integer> front = waitQueue.poll();
            if (front.getValue() > 0)
                maxHeap.offer(front);
        }
        return sb.length() == str.length() ? sb.toString() : "";
    }
}
