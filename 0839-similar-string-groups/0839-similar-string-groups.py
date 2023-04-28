class Solution:
    def bfs(self, start: int, adj: List[List[int]], visited: List[bool]) -> None:
        queue = deque([start])
        
        while queue:
            node = queue.popleft()
            visited[node] = True
            for neighbor in adj[node]:
                if not visited[neighbor]:
                    queue.append(neighbor)
    
    def isSimilar(self, a: str, b: str) -> bool:
        diff = 0
        for i in range(len(a)):
            if a[i] != b[i]:
                diff += 1
        
        return diff == 0 or diff == 2
    
    def numSimilarGroups(self, strs: List[str]) -> int:
        n = len(strs)
        adj = [[] for _ in range(n)]
        
        for i in range(n):
            for j in range(i + 1, n):
                if self.isSimilar(strs[i], strs[j]):
                    adj[i].append(j)
                    adj[j].append(i)
                    
        visited, ans = [False] * n, 0
        
        for i in range(n):
            if not visited[i]:
                self.bfs(i, adj, visited)
                ans += 1
        return ans