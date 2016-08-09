/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} head
 * @param {number} k
 * @return {ListNode}
 */
function ListNode(val) {
    this.val = val;
    this.next = null;
}

var rotateRight = function(head, k) {
    var getLength = function(head) {
        var len = 1;
        while (head && head.next) {
            len += 1;
            head = head.next;
        }
        return {
            'length': len,
            'tail': head
        }
    };
    if (head) {
        var len, tail, p = head;
        var r = getLength(head);
        len = r.length;
        tail = r.tail;
        var moveLeftBy = len - (k % len);
        while (p && moveLeftBy > 1) {
            p = p.next;
            moveLeftBy --;
        }
        var q = p.next;
        if (q) {
            tail.next = head;
            head = q;
            p.next = null;
        }   
    }
    return head;
    
};


var printListNode = function(ln) {
    var line = '';
    while (ln != null) {
        line += ln.val;
        line += ' -> ';
        ln = ln.next;
    }
    line += "NULL";
    console.log(line);
}
var c = new ListNode(0);
var p = c;
for (var i = 1; i < 10; i++) {
  p.next = new ListNode(i);
  p = p.next;
}
printListNode(c);
printListNode(rotateRight(c, 7));