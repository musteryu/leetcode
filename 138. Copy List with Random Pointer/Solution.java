/**
 * Definition for singly-linked list with a random pointer.
 * class RandomListNode {
 *     int label;
 *     RandomListNode next, random;
 *     RandomListNode(int x) { this.label = x; }
 * };
 */
public class Solution {
    
    public RandomListNode copyRandomList(RandomListNode head) {
        if (head == null) return head;
        HashMap<RandomListNode, RandomListNode> alreadyCopy = new HashMap<>();
        RandomListNode ptr = head;
        while (ptr != null) {
            alreadyCopy.put(ptr, new RandomListNode(ptr.label));
            ptr = ptr.next;
        }
        ptr = head;
        while (ptr != null) {
            RandomListNode copy = alreadyCopy.get(ptr);
            copy.next = ptr.next == null ? null : alreadyCopy.get(ptr.next);
            copy.random = ptr.random == null ? null : alreadyCopy.get(ptr.random);
            ptr = ptr.next;
        }
        return alreadyCopy.get(head);
    }
}