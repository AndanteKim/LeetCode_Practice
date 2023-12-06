class Solution:
    def totalMoney(self, n: int) -> int:
        ans, monday = 0, 1
        
        while n > 0:
            for day in range(min(n, 7)):
                ans += monday + day
            
            n -= 7
            monday += 1
        return ans