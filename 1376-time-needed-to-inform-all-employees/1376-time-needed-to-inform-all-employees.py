class Solution:
    def dfs(self, bossID: int, adj: List[List[int]], informTime: List[int]) -> int:
        return max([self.dfs(neighbor, adj, informTime) for neighbor in adj[bossID]] or [0]) + informTime[bossID]
    
    def numOfMinutes(self, n: int, headID: int, manager: List[int], informTime: List[int]) -> int:
        adj = [[] for _ in range(n)]
        
        for i in range(len(manager)):
            if manager[i] >= 0:
                adj[manager[i]].append(i)
        return self.dfs(headID, adj, informTime)