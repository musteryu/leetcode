/**
 * @param {number[]} candidates
 * @param {number} target
 * @return {number[][]}
 */
var combinationSum = function(candidates, target) {
  var i, len = candidates.length,
    results = [];
  candidates.sort((a, b) => b - a);

  var solve = function(chosens, left, index) {
    if (left === 0) {
      results.push(chosens.slice());
    } else if (left >= candidates[len - 1]) {
      for (var i = index; i < len; i++) {
        if (left >= candidates[i]) {
          chosens.push(candidates[i]);
          solve(chosens, left - candidates[i], i);
        }
      }
    }

    chosens.pop();
  };
  solve([], target, 0);

  results.forEach((element, index) => {
    element.reverse();
  });
  return results;
};

console.log(combinationSum([7, 6, 3, 2], 15));