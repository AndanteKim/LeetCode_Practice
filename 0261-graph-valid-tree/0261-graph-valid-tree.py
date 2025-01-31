class Solution:
    def validTree(self, n: int, edges: List[List[int]]) -> bool:
        # Iterative DFS
        if len(edges) != n - 1:
            return False

        graph = [[] for _ in range(n)]
        for u, v in edges:
            graph[u].append(v)
            graph[v].append(u)

        parent = {0: -1}
        stack = [0]

        while stack:
            node = stack.pop()
            for neighbor in graph[node]:
                if neighbor == parent[node]:
                    continue
                
                if neighbor in parent:
                    return False
                
                parent[neighbor] = node
                stack.append(neighbor)

        return len(parent) == n
        