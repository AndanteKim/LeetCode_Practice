class Solution:
    def snakesAndLadders(self, board: List[List[int]]) -> int:
        n = len(board)
        cells = [None] * (n ** 2 + 1)
        label = 1
        columns = list(range(0, n))
        for row in range(n-1, -1, -1):
            for col in columns:
                cells[label] = (row, col)
                label += 1
            columns.reverse()
        dist = [-1] * (n * n + 1)
        dist[1] = 0
        q = [(0, 1)]
        
        while q:
            d, curr = heapq.heappop(q)
            if d != dist[curr]:
                continue
            for next_d in range(curr + 1, min(curr + 6, n ** 2) + 1):
                row, col = cells[next_d]
                destination = (board[row][col] if board[row][col] != -1 else next_d)
                
                if dist[destination] == -1 or dist[curr] + 1 < dist[destination]:
                    dist[destination] = dist[curr] + 1
                    heapq.heappush(q, (dist[destination], destination))
        return dist[n * n]