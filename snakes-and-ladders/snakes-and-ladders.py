class Solution:
    def snakesAndLadders(self, board: List[List[int]]) -> int:
        n, label = len(board), 1
        columns, cells = list(range(0, n)), [None] * (n * n + 1)
        
        for row in range(n - 1, -1, -1):
            for col in columns:
                cells[label] = (row, col)
                label += 1
            columns.reverse()
        
        dist = [-1] * (n * n + 1)
        dist[1] = 0
        min_heap = [(0, 1)]
        
        while min_heap:
            d, curr = heappop(min_heap)
            
            if d != dist[curr]:
                continue
            
            for next in range(curr + 1, min(curr + 6, n * n) + 1):
                row, col = cells[next]
                dest = board[row][col] if board[row][col] != -1 else next
                if dist[dest] == -1 or dist[curr] + 1 < dist[dest]:
                    dist[dest] = dist[curr] + 1
                    heappush(min_heap, (dist[dest], dest))
        
        return dist[n * n]