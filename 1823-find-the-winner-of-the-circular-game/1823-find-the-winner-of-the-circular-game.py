class Solution:
    def winner_helper(self, n: int, k: int) -> int:
        if n == 1:
            return 0
        
        return (self.winner_helper(n - 1, k) + k) % n
    
    def findTheWinner(self, n: int, k: int) -> int:
        return self.winner_helper(n, k) + 1