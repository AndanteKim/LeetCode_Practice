class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        ans = [0] * n
        ans[0] = 1
        
        for i in range(1, n):
            ans[i] = ans[i - 1] * nums[i - 1]
        
        R = 1
        for i in range(n - 1, -1, -1):
            ans[i] = ans[i] * R
            R *= nums[i]
        
        return ans
        