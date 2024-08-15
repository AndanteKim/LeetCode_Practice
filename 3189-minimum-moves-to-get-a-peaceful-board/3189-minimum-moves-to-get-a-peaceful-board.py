class Solution:
    def minMoves(self, rooks: List[List[int]]) -> int:
        n, ans = len(rooks), 0
        rooks.sort()
        row = 0 
        for i in range(n):
            ans += abs(rooks[i][0] - row)
            rooks[i][0] = row
            row += 1
            
        rooks.sort(key = lambda x : x[1])
        col = 0
        for i in range(n):
            ans += abs(rooks[i][1] - col)
            rooks[i][1] = col
            col += 1
        
        return ans