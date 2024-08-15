class Solution:
    def minMoves(self, rooks: List[List[int]]) -> int:
        n, ans = len(rooks), 0
        
        rooks.sort()
        # Moves required to place rooks in each row
        for i in range(n):
            ans += abs(i - rooks[i][0])
        
        rooks.sort(key = lambda x: x[1])
        # Moves required to place rooks in each column
        for i in range(n):
            ans += abs(i - rooks[i][1])
            
        return ans