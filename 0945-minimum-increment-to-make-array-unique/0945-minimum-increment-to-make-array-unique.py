class Solution:
    def minIncrementForUnique(self, nums: List[int]) -> int:
        nums.sort()
        ans = need = 0
        
        for n in nums:
            ans += max(need - n, 0)
            need = max(need + 1, n + 1)
            
        return ans