class Solution:
    def findMaxK(self, nums: List[int]) -> int:
        ans, seen = -1, {num for num in nums}
        
        for n in seen:
            if -n in seen:
                ans = max(ans, max(n, -n))
            
        return ans
            
        