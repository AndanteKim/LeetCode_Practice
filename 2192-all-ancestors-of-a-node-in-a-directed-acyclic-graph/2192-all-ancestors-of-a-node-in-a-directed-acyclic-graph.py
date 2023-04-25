class Solution:
    def dfs(self, start: int, curr: int, adj: List[List[int]], ans: List[List[int]]) -> None:
        for neighbor in adj[curr]:
            if ans[neighbor] and ans[neighbor][-1] == start:
                continue
            ans[neighbor].append(start)
            self.dfs(start, neighbor, adj, ans)
    
    def getAncestors(self, n: int, edges: List[List[int]]) -> List[List[int]]:
        adj, ans = [[] for _ in range(n)], [[] for _ in range(n)]
        
        for start, end in edges:
            adj[start].append(end)
        
        for node in range(n):
            self.dfs(node, node, adj, ans)
            
        return ans
        