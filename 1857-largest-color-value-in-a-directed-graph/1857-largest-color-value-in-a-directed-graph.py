class Solution:
    def dfs(self, node: int, colors: List[str], adj: List[List[int]], count: List[List[int]], \
           visited: List[bool], inStack: List[bool]) -> int:
        if inStack[node]:
            return float('inf')
        if visited[node]:
            return count[node][ord(colors[node]) - ord('a')]
        
        visited[node], inStack[node] = True, True
        
        for neighbor in adj[node]:
            if self.dfs(neighbor, colors, adj, count, visited, inStack) == float('inf'):
                return float('inf')
            for i in range(26):
                count[node][i] = max(count[node][i], count[neighbor][i])
        count[node][ord(colors[node]) - ord('a')] += 1
        inStack[node] = False
        return count[node][ord(colors[node]) - ord('a')]
    
    def largestPathValue(self, colors: str, edges: List[List[int]]) -> int:
        n = len(colors)
        adj = [[] for _ in range(n)]
        for start, end in edges:
            adj[start].append(end)
            
        count = [[0] * 26 for _ in range(n)]
        visited, inStack = [False] * n, [False] * n
        ans = 0
        for i in range(n):
            ans = max(ans, self.dfs(i, colors, adj, count, visited, inStack))
        
        return -1 if ans == float('inf') else ans