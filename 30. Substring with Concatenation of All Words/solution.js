/**
 * @param {string} s
 * @param {string[]} words
 * @return {number[]}
 */
var findSubstring = function(s, words) {
  var wordNum = words.length;
  var wordLen = words[0].length;
  var i, j, sLen = s.length;
  var cache = {};
  var slice;
  var result = [];
  var wordFrequency = {};

  for (i = 0; i < wordNum; i++) {
    if (wordFrequency[words[i]] === undefined)
      wordFrequency[words[i]] = 1;
    else
      wordFrequency[words[i]]++;
  }

  var resetCache = function() {
    var i;
    for (i in wordFrequency) {
      cache[i] = 0;
    }
  }

  console.log(wordFrequency);
  resetCache();
  console.log(cache);

  for (i = 0; i <= sLen - wordNum * wordLen; i++) {
    resetCache();
    for (j = 0; j < wordNum; j++) {
      slice = s.substr(i + j * wordLen, wordLen);
      if (words.indexOf(slice) < 0) break; // slice is not in cache
      if (cache[slice] === wordFrequency[slice]) break; // cache frequency exceeds word frequency
      cache[slice]++;
    }
    if (j === wordNum) {
      result.push(i);
    }
  }
  return result;
};

var s = "barfoothefoobarman";
var words = ["foo", "bar"];
console.log(findSubstring(s, words));