class Solution:
    def findMaxAverage(self, nums: List[int], k: int) -> float:
        if len(nums) == 1 or len(nums) == k: return sum(nums)/k
        
        length = len(nums)
        tot = [0] * length
        tot[0] = nums[0]
        
        for i in range(1, length):
            tot[i] = tot[i-1] + nums[i]
            
        ans = tot[k-1] / k
        for i in range(k, length):
            ans = max(ans, (tot[i]-tot[i-k]) / k)
        return ans
            