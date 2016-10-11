class Solution(object):
    def palindromePairs(self, words):
        """
        :type words: List[str]
        :rtype: List[List[int]]
        """
        indices = {
            word: index for index, word in enumerate(words)
        }
        res = []
        for word in indices:
            i = indices[word]
            for j in range(len(word)):
                w1, w2 = word[:j], word[j:]
                w1_rev, w2_rev = w1[::-1], w2[::-1]
                if w1 == w1_rev and w2_rev in indices and indices[w2_rev] != i:
                    res.append([indices[w2_rev], i])
                if w2 == w2_rev and w1_rev in indices and indices[w1_rev] != i:
                    res.append([i, indices[w1_rev]])
            if word != '' and word == word[::-1] and '' in indices:
                res.append([indices[''], i])
        return res