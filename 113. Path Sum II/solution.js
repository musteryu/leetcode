/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @param {number} sum
 * @return {number[][]}
 */
var pathSum = function(root, sum) {
    if (root === null) return []
    if (root.val === sum && root.left === null && root.right === null) {
        return [[root.val]]
    }
    var result = []
    if (root.left !== null) {
        var lresult = pathSum(root.left, sum - root.val)
        if (lresult.length !== 0) {
            for (var r of lresult)
                r.unshift(root.val)
            result = result.concat(lresult)
        }
    }
    if (root.right !== null) {
        var rresult = pathSum(root.right, sum - root.val)
        if (rresult.length !== 0) {
            for (var r of rresult)
                r.unshift(root.val)
            result = result.concat(rresult)
        }
    }
    return result
};