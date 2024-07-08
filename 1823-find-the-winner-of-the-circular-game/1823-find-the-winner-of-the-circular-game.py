class Solution:
    def findTheWinner(self, n: int, k: int) -> int:
        ans = 0
        
        for i in range(2, n + 1):
            ans = (ans + k) % i
            
        # Add 1 to convert back to 1 indexing
        return ans + 1