class Solution:
    def dfs(self, node: int, colors: Set[int], color: int, graph: List[List[int]]) -> bool:
        if node in colors:
            if colors[node] != color:
                return False
            return True
        
        colors[node] = color
        for neighbor in graph[node]:
            if self.dfs(neighbor, colors, color ^ 1, graph) == False:
                return False
        return True
        
    
    def isBipartite(self, graph: List[List[int]]) -> bool:
        colors, n = dict(), len(graph)
        for node in range(n):
            if node not in colors:
                if self.dfs(node, colors, 0, graph) == False:
                    return False
        return True