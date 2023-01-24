class Solution:
    def snakesAndLadders(self, board: List[List[int]]) -> int:
        n = len(board)
        cells = [None] * (n ** 2 + 1)
        label = 1
        columns = list(range(0, n))
        for row in range(n - 1, -1, -1):
            for col in columns:
                cells[label] = (row, col)
                label += 1
            columns.reverse()
        dist = [-1] * (n * n + 1)
        
        q, dist[1] = deque([1]), 0
        
        while q:
            curr = q.popleft()
            for next_dice in range(curr + 1, min(curr + 6, n ** 2) + 1):
                row, col = cells[next_dice]
                destination = (board[row][col] if board[row][col] != -1 else next_dice)
                
                if dist[destination] == -1:
                    dist[destination] = dist[curr] + 1
                    q.append(destination)
        return dist[n * n]