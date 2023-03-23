class Solution:
    def makeConnected(self, n: int, connections: List[List[int]]) -> int:
        if len(connections) < n - 1:
            return -1
        
        adj = [[] for _ in range(n)]
        
        for start, end in connections:
            adj[start].append(end)
            adj[end].append(start)
            
        connected = 0
        visited = [False] * n
        
        for node in range(n):
            if not visited[node]:
                connected += 1
                queue = deque([node])
                visited[node] = True
                
                while queue:
                    curr = queue.popleft()
                    for neighbor in adj[curr]:
                        if not visited[neighbor]:
                            visited[neighbor] = True
                            queue.append(neighbor)
                
        
        return connected - 1