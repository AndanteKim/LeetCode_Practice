class Solution:
    def minimumSumSubarray(self, nums: List[int], l: int, r: int) -> int:
        ans, n = float('inf'), len(nums)

        for left in range(n):
            curr = 0
            for right in range(left, min(n, left + r)):
                curr += nums[right]
                if curr > 0 and right - left + 1 >= l:
                    ans = min(ans, curr)
        
        return -1 if ans == float('inf') else ans