/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
    var len = prices.length;
    if (len === 0) return 0;
    var win = new Array(3);
    for (var i = 0; i < 3; i++) {
        win[i] = new Array(len).fill(0);
    }
    var lastMost;
    for (var transaction = 1; transaction < 3; transaction++) {
        lastMost = win[transaction-1][0] - prices[0];
        for (var day = 1; day < len; day++) {
            win[transaction][day] = Math.max(win[transaction][day-1], lastMost + prices[day])
            lastMost = Math.max(win[transaction-1][day] - prices[day], lastMost);
        }
    }
    return win[2][len-1];
};