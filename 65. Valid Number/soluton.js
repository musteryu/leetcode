/**
 * @param {string} s
 * @return {boolean}
 */
var isNumber = function(s) {
    var isDigit = function(char) {
        return (char >= '0') && (char <= '9');
    };
    
    var isInt = function (s) {
        var isInt_ = function(s, alreadyHasFlag) {
            var len = s.length, i;
            if (len === 0) return false;
            if ((s[0] === '-' || s[0] === '+') && !alreadyHasFlag) 
                return isInt_(s.substring(1), true);
            if ((s[0] === '-' || s[0] === '+') && alreadyHasFlag) 
                return false;
            for (i = 0; i < len; i++) {
                if (!isDigit(s[i])) return false;
            }
            return true;
        }
        return isInt_(s, false);
    };
    
    var isFloat = function (s) {
        var isFloat_ = function(s, alreadyHasFlag, alreadyHasDot) {
            var len = s.length, i;
            if (len === 0) return false;
            if (s[0] === '-' || s[0] === '+') {
                if (alreadyHasFlag || alreadyHasDot)
                    return false;
                else
                    return isFloat_(s.substring(1), true, alreadyHasDot);
            }
            if (s[0] === '.') {
                if (alreadyHasDot)
                    return false;
                else return isFloat_(s.substring(1), alreadyHasFlag, true);
            }
            
            for (i = 0; i < len; i++) {
                if (isDigit(s[i])) continue;
                if (s[i] === '.') {
                    if (alreadyHasDot) return false; 
                    else alreadyHasDot = true;
                } else return false;
            }
            return true;
        };
        return isFloat_(s, false, false);
    };
    
    s = s.trim().toLowerCase();
    if (s.length === 0) return false;
    
    var e = s.indexOf('e');
    if (e < 0) { // No E
        return isFloat(s);
    } else if (e === 0) {
        return false;
    } else if (e === s.length - 1) {
        return false;
    } else if (s.indexOf('e', e+1) >= 0) {
        return false
    } else {
        return isFloat(s.substring(0, e)) && isInt(s.substring(e+1));
    }
};

var s = '+.4e4';
console.log(isNumber(s));