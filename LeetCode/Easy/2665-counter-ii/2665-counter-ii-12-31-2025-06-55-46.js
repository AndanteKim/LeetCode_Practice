/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
var createCounter = function(init) {
    let origin = init;
    
    return {
        increment: () => {
            return ++origin;
        },
        reset: () => {
            origin = init;
            return origin;
        },
        decrement: () => {
            return --origin;
        }
    };
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */