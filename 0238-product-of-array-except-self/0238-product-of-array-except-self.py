class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        # Time Complexity: O(n)
        # Space Complexity: O(n) since L, R prefix, suffix product array
        
        n = len(nums)
        
        L, R, ans = [0] * n, [0] * n, [0] * n
        
        L[0], R[n - 1] = 1, 1
        
        for i in range(1, n):
            L[i] = nums[i - 1] * L[i - 1]
            
        for i in range(n - 2, -1, -1):
            R[i] = nums[i + 1] * R[i + 1]
        
        
        for i in range(n):
            ans[i] = L[i] * R[i]
        
        return ans