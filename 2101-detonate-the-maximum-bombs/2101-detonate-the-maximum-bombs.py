class Solution:
    def dfs(self, curr: int, visited: Set[int], graph: DefaultDict[int, List[int]]) -> int:
        visited.add(curr)
        for neighbor in graph[curr]:
            if neighbor not in visited:
                self.dfs(neighbor, visited, graph)
        return len(visited)
    
    def maximumDetonation(self, bombs: List[List[int]]) -> int:
        graph = defaultdict(list)
        n = len(bombs)
        
        for i in range(n):
            for j in range(n):
                if i == j:
                    continue
                
                xi, yi, ri = bombs[i]
                xj, yj, _ = bombs[j]
                
                if (xi - xj) ** 2 + (yi - yj) ** 2 <= ri ** 2:
                    graph[i].append(j)
        
        ans = 0
        for i in range(n):
            visited = set()
            ans = max(ans, self.dfs(i, visited, graph))
        
        return ans
        