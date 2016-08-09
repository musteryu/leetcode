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
function TreeNode(val) {
    this.val = val;
    this.left = this.right = null;
};

var zigzagLevelOrder = function(root) {
    var result = [];
    var dfs = function(root, level) {
        if (root == null) return;
        if (result[level] == undefined)
            result[level] = [];
        if (level % 2 == 0) {
            result[level].push(root.val);
        } else {
            result[level].unshift(root.val);
        }
        dfs(root.left, level+1);
        dfs(root.right, level+1);
    };
    dfs(root);
    return result;
};

var zigzagLevelOrder = function(root) {
    if (root == null) return [];
    var result = [];
    var currLevel = [root];
    var level = 0;
    while (currLevel.length !== 0) {
        result.push([]);
        var currSize = currLevel.length;
        for (var i = 0; i < currSize; i++) {
            var head = currLevel.shift();
            if (level % 2 === 0) {
                result[level].push(head.val);
            } else {
                result[level].unshift(head.val);
            }
            if (head.left !== null)
                currLevel.push(head.left);
            if (head.right !== null)
                currLevel.push(head.right);
        }
        level ++;
    }
    return result;
}