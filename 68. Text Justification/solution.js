/**
 * @param {string[]} words
 * @param {number} maxWidth
 * @return {string[]}
 */
var fullJustify = function(words, maxWidth) {
    var i, j, l, wordsNum = words.length, len, line, lines = [], r, d, spaceNum;
    var spaces = function(num) {
        return new Array(num + 1).join(' ');
    };
    for (i = 0; i < wordsNum; i = j) {
        len = 0;
        for (j = i; j < wordsNum; j++) {
            len += words[j].length;
            if (len > maxWidth - (j - i)) {
                len -= words[j].length;
                break;
            }
        }
        line = [];
        for (l = i; l < j; l++) {
            line.push(words[l]);
        }
        lines.push({
            'words': line,
            'length': len
        });
        
    }
    result = [];
    for (i = 0; i < lines.length; i++) {
        r = [];
        line = lines[i];
        if (i === lines.length - 1) {
            for (j = 0; j < line.words.length - 1; j++) {
                r.push(line.words[j] + ' ');
            }
            r.push(line.words[j] + spaces(maxWidth - line.length - (j)));
            result.push(r.join(''));
        } else {
            if (line.words.length === 1) {
                result.push(line.words + spaces(maxWidth - line.length));
            } else {
                d = line.words.length - 1;
                for (j = 0; j < line.words.length; j++) {
                    if (j === line.words.length - 1)
                        r.push(line.words[j]);
                    else {
                        spaceNum = Math.ceil((maxWidth - line.length) / d);
                        r.push(line.words[j] + spaces(spaceNum));
                        line.length += spaceNum;
                        d --;
                    }
                }
                result.push(r.join(''));
            }
        }
    }
    return result;
};

var words = ["This", "is", "an", "example", "of", "text", "justification."];
console.log(fullJustify(words, 16));