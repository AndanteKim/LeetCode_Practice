class Solution:
    def isBipartite(self, graph: List[List[int]]) -> bool:
        n, colors = len(graph), dict()
        
        for node in range(n):
            if node in colors:
                continue
            
            queue = deque([node])
            colors[node] = 0
            
            while queue:
                curr = queue.popleft()
                for neighbor in graph[curr]:
                    if neighbor not in colors:
                        colors[neighbor] = colors[curr] ^ 1
                        queue.append(neighbor)
                    elif colors[neighbor] == colors[curr]:
                        return False
        return True
        