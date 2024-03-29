class Solution:
    def dfs(self, node: int, adj: List[List[int]], visited: List[bool], inStack: List[bool]) -> bool:
        if inStack[node]:
            return True
        
        if visited[node]:
            return False
        visited[node] = True
        inStack[node] = True
        for neighbor in adj[node]:
            if self.dfs(neighbor, adj, visited, inStack):
                return True
        inStack[node] = False
        return False
    
    def eventualSafeNodes(self, graph: List[List[int]]) -> List[int]:
        n = len(graph)
        
        visited, inStack = [False] * n, [False] * n
        
        for i in range(n):
            self.dfs(i, graph, visited, inStack)
        
        ans = []
        for i in range(n):
            if not inStack[i]:
                ans.append(i)
        
        return ans