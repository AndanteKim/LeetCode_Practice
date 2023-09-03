class Solution:
    def increasingTriplet(self, nums: List[int]) -> bool:
        n = len(nums)
        if n < 3:
            return False
        
        dp = [0] * n
        dp[0] = nums[0]
        
        for i in range(1, n - 1):
            dp[i] = min(dp[i - 1], nums[i])
        
        mx = nums[n - 1]
        for i in range(n - 2, 0, -1):
            mn = dp[i - 1]
            mx = max(mx, nums[i + 1])
            
            if mn < nums[i] < mx:
                return True
        
        return False