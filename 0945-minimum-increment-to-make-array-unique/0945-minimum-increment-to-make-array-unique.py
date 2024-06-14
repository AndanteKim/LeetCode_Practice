class Solution:
    def minIncrementForUnique(self, nums: List[int]) -> int:
        c = Counter(nums)
        
        ans = need = 0
        for x in sorted(c):
            ans += c[x] * max(need - x, 0) + ((c[x] * (c[x] - 1)) >> 1)
            need = max(need, x) + c[x]
            
        return ans