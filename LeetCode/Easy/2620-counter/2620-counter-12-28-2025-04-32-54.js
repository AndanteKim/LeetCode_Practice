/**
 * @param {number} n
 * @return {Function} counter
 */
var createCounter = function(n) {
    let call = n;
    return function() {
        return call++;
    };
};

/** 
 * const counter = createCounter(10)
 * counter() // 10
 * counter() // 11
 * counter() // 12
 */