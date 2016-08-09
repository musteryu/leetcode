/**
 * @param {string} path
 * @return {string}
 */
var simplifyPath = function(path) {
    var components = path.split('/');
    console.log(components);
    var simplified = [];
    var i = 0;
    for (var c of components) {
        if (c === '' || c === '.') continue;
        else if (c === '..') simplified.pop();
        else simplified.push('/' + c);
    }
    if (simplified.length === 0) return '/';
    return simplified.join('');
};

var path = "/.../f///a/..";
console.log(simplifyPath(path));