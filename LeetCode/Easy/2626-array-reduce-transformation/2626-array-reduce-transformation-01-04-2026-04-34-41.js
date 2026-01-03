/**
 * @param {number[]} nums
 * @param {Function} fn
 * @param {number} init
 * @return {number}
 */
var reduce = function(nums, fn, init) {
    let accumulator = init;
    
    for (const idx in nums) accumulator = fn(accumulator, nums[idx]);

    return accumulator;
};