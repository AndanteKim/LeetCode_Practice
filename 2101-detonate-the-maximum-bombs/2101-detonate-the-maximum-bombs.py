class Solution:
    def dfs(self, node: int, visited: Set[int], graph: DefaultDict[int, List[int]]) -> int:
        stack = [node]
        visited.add(node)
        
        while stack:
            curr = stack.pop()
            for neighbor in graph[curr]:
                if neighbor not in visited:
                    visited.add(neighbor)
                    stack.append(neighbor)
                    
        return len(visited)
    
    def maximumDetonation(self, bombs: List[List[int]]) -> int:
        graph = defaultdict(list)
        n = len(bombs)
        
        for i in range(n):
            for j in range(n):
                if i == j:
                    continue
                    
                xi, yi, ri = bombs[i]
                xj, yj, rj = bombs[j]
                
                if (xi - xj) ** 2 + (yi - yj) ** 2 <= ri ** 2:
                    graph[i].append(j)
        
        ans = 0
        for i in range(n):
            visited = set()
            ans = max(ans, self.dfs(i, visited, graph))
            
        return ans