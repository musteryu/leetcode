/**
 * Definition for an interval.
 * function Interval(start, end) {
 *     this.start = start;
 *     this.end = end;
 * }
 */
/**
 * @param {Interval[]} intervals
 * @return {Interval[]}
 */
function Interval(start, end) {
  this.start = start;
  this.end = end;
}
var merge = function(intervals) {
  if (intervals.length === 0) return [];
  intervals.sort((a, b) => a.start - b.start);
  var result = [intervals[0]],
    i, len = intervals.length,
    top;
  for (i = 1; i < len; i++) {
    top = result[result.length - 1];
    if (intervals[i].start <= top.end) top.end = Math.max(intervals[i].end, top.end);
    else result.push(intervals[i]);
  }
  return result;
};
var intervals = [
  [1, 3],
  [2, 6],
  [8, 10],
  [15, 18]
].map((e, i) => new Interval(e[0], e[1]));
var result = merge(intervals);
result.forEach((e, i) => console.log('[' + e.start + ',' + e.end + ']'));