/**
 * @param {string[]} tokens
 * @return {number}
 */
var evalRPN = function(tokens) {
    var len = tokens.length;
    var nums = [];
    var result;
    var curr;
    var num1, num2;
    for (var i = 0; i < len; i++) {
        switch ((curr = tokens[i])) {
            case "+":
                num2 = nums.pop();
                num1 = nums.pop();
                nums.push(num1 + num2);
                break;
            case "-":
                num2 = nums.pop();
                num1 = nums.pop();
                nums.push(num1 - num2);
                break;
            case "*":
                num2 = nums.pop();
                num1 = nums.pop();
                nums.push(num1 * num2);
                break;
            case "/":
                num2 = nums.pop();
                num1 = nums.pop();
                nums.push(Math.trunc(num1 / num2));
                break;
            default:
                nums.push(Number.parseInt(curr));
        }
    }
    return nums.pop();
};

console.log(evalRPN(["10","6","9","3","+","-11","*","/","*","17","+","5","+"]));