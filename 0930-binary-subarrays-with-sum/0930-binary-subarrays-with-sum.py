class Solution:
    def numSubarraysWithSum(self, nums: List[int], goal: int) -> int:
        i_lo = i_hi = 0
        sum_lo = sum_hi = 0
        ans = 0
        for j, x in enumerate(nums):
            sum_lo += x
            while i_lo < j and sum_lo > goal:
                sum_lo -= nums[i_lo]
                i_lo += 1
            
            sum_hi += x
            while i_hi < j and (sum_hi > goal or sum_hi == goal and not nums[i_hi]):
                sum_hi -= nums[i_hi]
                i_hi += 1
            
            if sum_lo == goal:
                ans += i_hi - i_lo + 1
            
        return ans