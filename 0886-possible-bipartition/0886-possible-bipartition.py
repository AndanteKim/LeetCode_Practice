class Solution:
    def bfs(self, start: int, color: List[int], adj: List[List[int]]) -> bool:
        queue = deque([start])
        color[start] = 0
        while queue:
            node = queue.popleft()
            for neighbor in adj[node]:
                if color[neighbor] == color[node]:
                    return False
                if color[neighbor] == -1:
                    color[neighbor] = 1 - color[node]
                    queue.append(neighbor)
        return True
    
    def possibleBipartition(self, n: int, dislikes: List[List[int]]) -> bool:
        if not dislikes:
            return True
        
        adj = [[] for _ in range(n + 1)]
        
        for start, end in dislikes:
            adj[start].append(end)
            adj[end].append(start)
            
        color = [-1] * (n + 1)
        for i in range(1, n + 1):
            if color[i] == -1:
                if not self.bfs(i, color, adj):
                    return False
        
        return True
        