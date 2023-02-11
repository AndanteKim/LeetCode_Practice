class Solution:
    def shortestAlternatingPaths(self, n: int, redEdges: List[List[int]], blueEdges: List[List[int]]) -> List[int]:
        adj = defaultdict(list)
        for start, dest in redEdges:
            adj[start].append((dest, 0))
        
        for start, dest in blueEdges:
            adj[start].append((dest, 1))
        
        ans, q = [-1] * n, deque([])
        visit = [[False] * 2 for _ in range(n)]
        q.append((0, 0, -1))
        ans[0] = 0
        
        while q:
            node, steps, prevColor = q.popleft()
            
            for neighbor, color in adj[node]:
                if not visit[neighbor][color] and color != prevColor:
                    visit[neighbor][color] = True
                    q.append((neighbor, 1 + steps, color))
                    if ans[neighbor] == -1:
                        ans[neighbor] = 1 + steps
                    
                
        return ans
            
            