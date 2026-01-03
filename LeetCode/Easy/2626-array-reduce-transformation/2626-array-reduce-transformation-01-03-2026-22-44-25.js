/**
 * @param {number[]} nums
 * @param {Function} fn
 * @param {number} init
 * @return {number}
 */
var reduce = function(nums, fn, init) {
    if (nums.length == 0) return init;
    var ans = init;
    for (let i = 0; i < nums.length; ++i) {
        ans = fn(ans, nums[i]);
    }

    return ans;
};