class Solution:
    def dfs(self, node: int, adj: List[List[int]], visited: List[bool]) -> None:
        visited[node] = True
        for neighbor in adj[node]:
            if not visited[neighbor]:
                self.dfs(neighbor, adj, visited)
    
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
                    
        visited = [False] * n
        ans = 0
        for i in range(n):
            if not visited[i]:
                self.dfs(i, adj, visited)
                ans += 1
        return ans