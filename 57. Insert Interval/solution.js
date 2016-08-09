/**
 * Definition for an interval.
 * function Interval(start, end) {
 *     this.start = start;
 *     this.end = end;
 * }
 */
/**
 * @param {Interval[]} intervals
 * @param {Interval} newInterval
 * @return {Interval[]}
 */
function Interval(start, end) {
  this.start = start;
  this.end = end;
}
var insert = function(intervals, newInterval) {
  var result = [new Interval(-Infinity, -Infinity)].concat(intervals).concat([new Interval(Infinity, Infinity)]);
  var i, len = intervals.length,
    startIndex, endIndex,
    start, end;
  for (i = 0; i <= len + 1; i++) {
    if (newInterval.start < result[i].start) {
      startIndex = i;
      start = newInterval.start;
      break;
    }
    if (newInterval.start <= result[i].end) {
      startIndex = i;
      start = result[i].start;
      break;
    }
  }
  for (i = len + 1; i >= 0; i--) {
    if (newInterval.end > result[i].end) {
      endIndex = i;
      end = newInterval.end;
      break;
    }
    if (newInterval.end >= result[i].start) {
      endIndex = i;
      end = result[i].end;
      break;
    }
  }
  result = result.slice(0, startIndex).concat([new Interval(start, end)]).concat(result.slice(endIndex + 1));
  return result.filter((e, i) => e.start !== -Infinity && e.start !== Infinity);
};
var intervals = [
  [1, 3],
  [6, 9]
].map((e, i) => new Interval(e[0], e[1]));
var newInterval = new Interval(2, 5);
insert(intervals, newInterval).forEach((e, i) => console.log('(' + e.start + ',' + e.end + ')'));