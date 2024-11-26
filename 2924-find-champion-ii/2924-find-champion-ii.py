class Solution:
    def findChampion(self, n: int, edges: List[List[int]]) -> int:
        def dfs(start: int, visited: List[bool]) -> None:
            visited[start] = True
            if not graph[start]:
                return
            
            for neighbor in graph[start]:
                if not visited[neighbor]:
                    dfs(neighbor, visited)
        
        graph, m = defaultdict(list), len(edges)
        
        for start, end in edges:
            graph[start].append(end)
            
        for node in range(n):
            visited = [False] * n
            dfs(node, visited)
            
            if sum(visited) == n:
                return node
        
        return -1