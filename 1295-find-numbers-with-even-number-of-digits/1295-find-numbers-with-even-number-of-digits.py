class Solution:
    def findNumbers(self, nums: List[int]) -> int:
        ans = 0

        for num in nums:
            digits = 0
            while num > 0:
                digits += 1
                num //= 10
            
            if digits % 2 == 0:
                ans += 1
        
        return ans