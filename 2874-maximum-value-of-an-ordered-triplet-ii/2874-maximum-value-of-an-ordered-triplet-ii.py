class Solution:
    def maximumTripletValue(self, nums: List[int]) -> int:
        ans, imax, dmax = 0, 0, 0
        n = len(nums)
        
        for k in range(n):
            ans = max(ans, dmax * nums[k])
            dmax = max(dmax, imax - nums[k])
            imax = max(imax, nums[k])

        return ans