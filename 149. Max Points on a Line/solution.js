/**
 * Definition for a point.
 * function Point(x, y) {
 *     this.x = x;
 *     this.y = y;
 * }
 */
/**
 * @param {Point[]} points
 * @return {number}
 */
var maxPoints = function(points) {
    var maxNum = 0;
    var pointsNum = points.length;
    if (pointsNum === 1) return 1;

    var cmp = function(a, b) {
        if (a.x === b.x && a.y === b.y) return 0;
        else if (a.x === b.x) return a.y - b.y;
        else return a.x - b.x;
    };

    var slop = function(a, b) {
        if (cmp(a, b) === 0) return -Infinity;
        var s = (a.y - b.y) / (a.x - b.x);
        if (s === -Infinity || s === Infinity) return -Number.MAX_VALUE;
        else return s;
    };

    var find = function(origin) {
        var slops = points.map((p, i) => slop(p, origin));
        slops.sort((a, b) => a - b);
        var slow = 0;
        while (slops[slow] === -Infinity) slow++;
        if (slow >= pointsNum) return slow;
        var originNum = slow, fast = slow+1;
        while (fast < pointsNum) {
            if (slops[fast] === slops[fast-1]) fast++;
            else {
                maxNum = Math.max(fast - slow + originNum, maxNum);
                slow = fast;
                fast++;
            }
        }
        maxNum = Math.max(fast - slow + originNum, maxNum);
        return -1;
    };

    points.sort(cmp);
    var m;
    for (var i = 0; i < pointsNum; i++) {
        if (i > 0 && cmp(points[i], points[i-1]) === 0) continue;
        if ((m = find(points[i])) > 0) return m;
    }
    return maxNum;
};