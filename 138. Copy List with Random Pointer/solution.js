/**
 * Definition for singly-linked list with a random pointer.
 * function RandomListNode(label) {
 *     this.label = label;
 *     this.next = this.random = null;
 * }
 */

/**
 * @param {RandomListNode} head
 * @return {RandomListNode}
 */
var copyRandomList = function(head) {
    var nodes = {};
    var dfs = function(from) {
        if (from === null || from === undefined) return from;
        var node = new RandomListNode(from.label);
        nodes[from.label] = node;
        node.next = dfs(from.next);
        node.random = nodes[from.random];
        return node;
    }
    return dfs(head);
};