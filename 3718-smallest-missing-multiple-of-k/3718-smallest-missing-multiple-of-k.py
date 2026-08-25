class Solution:
    def missingMultiple(self, nums: List[int], k: int) -> int:
        ans, seen = k, set(nums)

        while ans in seen:
            ans += k
        
        return ans