public class AllOne {
    private Node head;
    private Node tail;
    private HashMap<String, Node> keyToNode;
    /** Initialize your data structure here. */
    public AllOne() {
        head = new Node(0);
        tail = new Node(Integer.MAX_VALUE);
        head.next = tail;
        tail.last = head;
        keyToNode = new HashMap<>();
    }
    
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    public void inc(String key) {
        if (!keyToNode.containsKey(key)) {
            after(head, 1).keys.add(key);
            keyToNode.put(key, head.next);
        } else {
            Node node = keyToNode.get(key);
            after(node, node.val + 1).keys.add(key);
            keyToNode.put(key, node.next);
            rmKey(node, key);
        }
    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    public void dec(String key) {
        if (!keyToNode.containsKey(key)) return;
        Node node = keyToNode.get(key);
        Node bf = before(node, node.val - 1);
        if (bf == head)
            keyToNode.remove(key);
        else {
            keyToNode.put(key, bf);
            bf.keys.add(key);
        }
        rmKey(node, key);
    }
    
    /** Returns one of the keys with maximal value. */
    public String getMaxKey() {
        if (head.next == tail) return "";
        else return tail.last.keys.iterator().next();
    }
    
    /** Returns one of the keys with Minimal value. */
    public String getMinKey() {
        if (head.next == tail) return "";
        else return head.next.keys.iterator().next();
    }

    private static class Node {
        int val;
        HashSet<String> keys = new HashSet<>();
        Node last = null, next = null;
        Node(int v) {
            val = v;
        }
    }

    private Node before(Node n, int v) {
        if (n.last.val == v) return n.last;
        Node newN = new Node(v);
        newN.next = n;
        newN.last = n.last;
        n.last = n.last.next = newN;
        return newN;
    }

    private Node after(Node n, int v) {
        if (n.next.val == v) return n.next;
        Node newN = new Node(v);
        newN.last = n;
        newN.next = n.next;
        n.next = n.next.last = newN;
        return newN;
    }

    private void remove(Node n) {
        n.last.next = n.next;
        n.next.last = n.last;
        n.next = n.last = null;
    }

    private void rmKey(Node n, String key) {
        n.keys.remove(key);
        if (n.keys.isEmpty())
            remove(n);
    }
}

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne obj = new AllOne();
 * obj.inc(key);
 * obj.dec(key);
 * String param_3 = obj.getMaxKey();
 * String param_4 = obj.getMinKey();
 */