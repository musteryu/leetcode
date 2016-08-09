/**
 * @param {number} n
 * @param {number} k
 * @return {string}
 */
var getPermutation = function(n, k) {
  var facCache = [],
    result = [],
    next, num, i, j, fac, used = [];
  var factorial = function(n) {
    var sum = 1,
      i;
    if (facCache[n]) return facCache[n];
    for (i = 0; i <= n; i++) {
      if (i !== 0) sum *= i;
      facCache[i] = sum;
    }
    return sum;
  };
  var unused = function(index) {
    var i = 0,
      num = 0;
    while (i <= index) {
      num++;
      if (!used[num]) i++;
    }
    return num;
  }
  factorial(n - 1);
  k = k - 1;
  for (i = 0; i < n; i++) {
    fac = facCache.pop();
    next = Math.floor(k / fac);
    k = k % fac;
    num = unused(next);
    result.push(num);
    used[num] = true;
  }
  return result.join('');
};
for (var i = 1; i < 20; i++) console.log(getPermutation(9, i))