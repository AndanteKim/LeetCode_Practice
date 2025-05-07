class Solution:
    def minTimeToReach(self, moveTime: List[List[int]]) -> int:
        n, m = len(moveTime), len(moveTime[0])
        memo = [[float('inf')] * m for _ in range(n)]
        pq = [(0, 0, 0)]
        
        while pq:
            time, i, j = heappop(pq)

            if time >= memo[i][j]:
                continue
            memo[i][j] = min(memo[i][j], time)

            if i > 0:
                heappush(pq, (1 + max(time, moveTime[i - 1][j]), i - 1, j)) 

            if i < n - 1:
                heappush(pq, (1 + max(time, moveTime[i + 1][j]), i + 1, j))
            
            if j > 0:
                heappush(pq, (1 + max(time, moveTime[i][j - 1]), i, j - 1))

            if j < m - 1:
                heappush(pq, (1 + max(time, moveTime[i][j + 1]), i, j + 1))
        
        return memo[n - 1][m - 1]