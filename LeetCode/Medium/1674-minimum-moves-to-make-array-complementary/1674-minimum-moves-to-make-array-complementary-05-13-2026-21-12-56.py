class Solution:
    def minMoves(self, nums: List[int], limit: int) -> int:
        n = len(nums)
        diff = [0] * (2 * limit + 2)

        for i in range(n >> 1):
            a = min(nums[i], nums[n - 1 - i])
            b = max(nums[i], nums[n - 1 - i])

            diff[2] += 2
            diff[a + 1] -= 1
            diff[a + b] -= 1
            diff[a + b + 1] += 1
            diff[b + limit + 1] += 1
        
        min_ops, curr_ops = n, 0

        for c in range(2, 2 * limit + 1):
            curr_ops += diff[c]
            if curr_ops < min_ops:
                min_ops = curr_ops
        
        return min_ops