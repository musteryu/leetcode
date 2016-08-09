/**
 * @param {number[]} height
 * @return {number}
 */
/*
var trap = function(height) {
  var result = 0,
    len = height.length,
    i;
  var fill = function(start, end) {
    var h = Math.min(height[start], height[end]),
      i;
    for (i = start; i < end; i++) {
      if (height[i] < h) {
        result += (h - height[i]);
        height[i] = h;
      }
    }
  };

  var findTrapAndFill = function(start, lastMax, lastMaxIndex) {
    if (start >= len - 1) return;
    var i;
    if (height[start + 1] >= height[start]) {
      fill(lastMaxIndex, start + 1);
      i = start + 1;
    } else {
      for (i = start + 2; i < len; i++) {
        if (height[i] > height[start + 1]) {
          if (height[i] > height[start]) {
            fill(lastMaxIndex, i);
          } else {
            fill(start, i);
          }
          break;
        }
      }
      if (i === len) {
        return findTrapAndFill(start + 1, lastMax, lastMaxIndex);
      }
    }
    if (height[i] >= lastMax) {
      findTrapAndFill(i, height[i], i);
    } else {
      findTrapAndFill(i, lastMax, lastMaxIndex);
    }
  }
  for (i = 0; i < len; i++) {
    if (height[i] > 0) {
      findTrapAndFill(i, height[i], i);
      return result;
    }
  }
  return 0;

}; */

/* From bolaoshi
var trap = function(height) {
  var i, len = height.length,
    result = 0,
    currentMax = 0;
  var lscan = [],
    rscan = [];
  for (i = 0; i < len; i++) {
    if (height[i] > currentMax)
      currentMax = height[i];
    lscan[i] = currentMax;
  }

  currentMax = 0;
  for (i = len - 1; i >= 0; i--) {
    if (height[i] > currentMax)
      currentMax = height[i];
    rscan[i] = currentMax;
  }

  for (i = 0; i < len; i++) {
    result += (Math.min(rscan[i], lscan[i]) - height[i]);
  }

  return result;
}
*/

var trap = function(height) {
  if (height == null || height.length == 0) return 0;
  var leftMax = 0,
    rightMax = 0,
    trapped = 0,
    left = 0,
    right = height.length - 1;
  while (left < right) {
    leftMax = leftMax > height[left] ? leftMax : height[left];
    rightMax = rightMax > height[right] ? rightMax : height[right];
    trapped += leftMax < rightMax ? leftMax - height[left++] : rightMax - height[right--];
  }
  return trapped;
}

var height = [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1];
console.log(trap(height));
console.log(height);