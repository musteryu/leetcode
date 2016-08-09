/**
 * @param {string} beginWord
 * @param {string} endWord
 * @param {Set} wordList
 *   Note: wordList is a Set object, see:
 *   https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Set
 * @return {number}
 */
/**
 * @param {string} beginWord
 * @param {string} endWord
 * @param {Set} wordList
 *   Note: wordList is a Set object, see:
 *   https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Set
 * @return {number}
 */
const ladderLength = (beginWord, endWord, wordList) => {
    const nextWords = (word) => {
        var next = [];
        const alphabets = "abcedfghijklmnopqrstuvwxyz";
        for (var i = 0, len = word.length; i < len; i++) {
            for (var char of alphabets) {
                var newWord = word.substring(0, i) + char + word.substring(i+1);
                if (newWord !== word && wordList.has(newWord)) next.push(newWord);
            }
        }
        return next;
    };
    const balancedDfs = (forward, backward, reverse, forwardLevel, backwardLevel) => {
        if (forward.size === 0) return 0;
        if (forward.size > backward.size) return balancedDfs(backward, forward, !reverse, backwardLevel, forwardLevel);
        for (var word of forward)
            wordList.delete(word);
        var nextForward = new Set();
        for (word of forward) {
            for (var nextWord of nextWords(word)) {
                if (backward.has(nextWord)) {
                    return forwardLevel + backwardLevel;
                } else {
                    nextForward.add(nextWord);
                }
            }
        }
        return balancedDfs(nextForward, backward, reverse, forwardLevel + 1, backwardLevel);
    };

    return balancedDfs(new Set([beginWord]), new Set([endWord]), false, 1, 1);
};
console.log(
    ladderLength(
        "a",
        "c",
        new Set(["a", "b", "c"])
    )
)