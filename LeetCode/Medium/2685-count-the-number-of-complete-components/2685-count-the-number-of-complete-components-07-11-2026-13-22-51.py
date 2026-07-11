class Solution:
    def countCompleteComponents(self, n: int, edges: List[List[int]]) -> int:
        graph = [[] * n for _ in range(n)]
        component_freq = defaultdict(int)

        for v in range(n):
            graph[v] = [v]

        for u, v in edges:
            graph[u].append(v)
            graph[v].append(u)

        for v in range(n):
            neighbors = tuple(sorted(graph[v]))
            component_freq[neighbors] += 1
        
        return sum(
            1
            for neighbors, freq in component_freq.items()
            if len(neighbors) == freq
        )