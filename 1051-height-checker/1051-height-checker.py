class Solution:
    def heightChecker(self, heights: List[int]) -> int:
        n, ans = max(heights), 0
        count = [0] * (n + 1)
        
        for height in heights:
            count[height] += 1
        
        i = 1
        for height in heights:
            while count[i] == 0:
                i += 1
            
            if height != i:
                ans += 1
            count[i] -= 1
                
        return ans