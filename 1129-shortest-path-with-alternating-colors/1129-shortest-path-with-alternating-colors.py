class Solution:
    def shortestAlternatingPaths(self, n: int, redEdges: List[List[int]], blueEdges: List[List[int]]) -> List[int]:
        ans = [-1] * n
        adj = [[] for _ in range(n)]
        
        for start, end in redEdges:
            adj[start].append((end, 0))
        
        for start, end in blueEdges:
            adj[start].append((end, 1))
        
        queue = deque([(0, 0, -1)])
        visited = [[False, False] for _ in range(n)]
        
        while queue:
            node, distance, prevColor = queue.popleft()
            
            ans[node] = distance if ans[node] == -1 else min(ans[node], distance)
            
            for neighbor, color in adj[node]:
                if color != prevColor and not visited[neighbor][color]:
                    visited[neighbor][color] = True
                    queue.append((neighbor, distance + 1, color))    
        
        return ans