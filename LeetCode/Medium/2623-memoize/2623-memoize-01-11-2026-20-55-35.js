/**
 * @param {Function} fn
 * @return {Function}
 */
function memoize(fn) {
    const cache = {};
    return function(...args) {
        // convert arguments to string
        let key = '';
        for (const arg of arguments) {
            key += ',' + arg;
        }

        if (key in cache) return cache[key];
        const funcOutput = fn(...arguments);
        cache[key] = funcOutput;
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