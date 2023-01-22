class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        n = len(nums)
        if n == 0: return 0
        ans, prefix_sum = 2**31 - 1, [0] * (n+1)
        for i in range(1, n+1):
            prefix_sum[i] = prefix_sum[i-1] + nums[i-1]
        for i in range(1, n+1):
            to_find = target + prefix_sum[i-1]
            bound = bisect.bisect_left(prefix_sum, to_find)
            if bound != len(prefix_sum):
                ans = min(ans, bound - i + 1)
                    
        return ans if ans != 2**31-1 else 0