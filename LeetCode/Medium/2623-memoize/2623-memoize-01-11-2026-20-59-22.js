/**
 * @param {Function} fn
 * @return {Function}
 */
function memoize(fn) {
    const cache = new Map();
    return function(...args) {
        let key = arguments[0];
        if (arguments[1]) key += arguments[1] * 100001;
        const ans = cache.get(key);
        if (ans !== undefined) return ans;

        const funcOutput = fn.apply(null, arguments);
        cache.set(key, funcOutput);
        return funcOutput;
    }
}


/** 
 * let callCount = 0;
 * const memoizedFn = memoize(function (a, b) {
 *	 callCount += 1;
 *   return a + b;
 * })
 * memoizedFn(2, 3) // 5
 * memoizedFn(2, 3) // 5
 * console.log(callCount) // 1 
 */