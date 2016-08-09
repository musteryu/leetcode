/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number[][]}
 */
var levelOrderBottom = function(root) {
    if (root === null) return [];
    var currLevel = [root];
    var result = [];
    while (currLevel.length > 0) {
        result.unshift([]);
        var currLen = currLevel.length;
        for (var i = 0; i < currLen; i++) {
            var head = currLevel.shift();
            result[0].push(head.val);
            if (head.left !== null) 
                currLevel.push(head.left);
            if (head.right !== null)
                currLevel.push(head.right);
        }
    }
    return result;
};