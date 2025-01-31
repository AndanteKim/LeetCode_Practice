class Solution:
    def validTree(self, n: int, edges: List[List[int]]) -> bool:
        if len(edges) != n - 1:
            return False

        graph = [[] for _ in range(n)]
        for u, v in edges:
            graph[u].append(v)
            graph[v].append(u)

        queue = deque([0])
        parent = {0 : -1}

        while queue:
            node = queue.popleft()

            for neighbor in graph[node]:
                if neighbor == parent[node]:
                    continue

                if neighbor in parent:
                    return False

                parent[neighbor] = node
                queue.append(neighbor)

        return len(parent) == n
