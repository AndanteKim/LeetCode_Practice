class Solution:
    ans = -1
    def dfs(self, node: int, edges: List[int], dist: DefaultDict[int, int],\
            visited: List[bool]) -> None:
        visited[node] = True
        neighbor = edges[node]
        
        if neighbor != -1 and not visited[neighbor]:
            dist[neighbor] = dist[node] + 1
            self.dfs(neighbor, edges, dist, visited)
        elif neighbor != -1 and dist.get(neighbor, 0) > 0:
            self.ans = max(self.ans, dist[node] - dist[neighbor] + 1)
    
    def longestCycle(self, edges: List[int]) -> int:
        n = len(edges)
        visited = [False] * n
        
        for node in range(n):
            if not visited[node]:
                dist = defaultdict(int)
                dist[node] = 1
                self.dfs(node, edges, dist, visited)
        
        return self.ans
        