class Solution:
    def findMaxAverage(self, nums: List[int], k: int) -> float:
        curr = 0
        for i in range(k):
            curr += nums[i]
        ans = curr    
        for i in range(k, len(nums)):
            curr = curr - nums[i-k] + nums[i]
            ans = max(ans, curr)
            
        return ans/k
            