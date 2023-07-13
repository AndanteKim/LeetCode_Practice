class Solution:
    def dfs(self, node: int, adj: List[List[int]], visited: List[bool], inStack: List[bool]) -> bool:
        if inStack[node]:
            return True
        
        if visited[node]:
            return False
        
        visited[node], inStack[node] = True, True
        for neighbor in adj[node]:
            if self.dfs(neighbor, adj, visited, inStack):
                return True
        inStack[node] = False
        return False
    
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        adj = [[] for _ in range(numCourses)]
        
        for curr, need in prerequisites:
            adj[need].append(curr)
        
        visited, inStack = [False] * numCourses, [False] * numCourses
        for i in range(numCourses):
            if self.dfs(i, adj, visited, inStack):
                return False
        return True