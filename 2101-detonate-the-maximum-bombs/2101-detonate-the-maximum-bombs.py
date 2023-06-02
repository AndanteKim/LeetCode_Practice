class Solution:
    def bfs(self, node: int, visited: Set[int], graph: DefaultDict[int, List[int]]) -> int:
        queue = deque([node])
        visited.add(node)
        
        while queue:
            curr = queue.popleft()
            for neighbor in graph[curr]:
                if neighbor not in visited:
                    visited.add(neighbor)
                    queue.append(neighbor)
                    
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
            ans = max(ans, self.bfs(i, visited, graph))
            
        return ans