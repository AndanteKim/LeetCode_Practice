class Solution:
    def countCompleteComponents(self, n: int, edges: List[List[int]]) -> int:
        # Adjacency lists for each vertex
        graph = [[] for _ in range(n)]
        # Map to store frequency of each unique adjacency list
        component_freq = defaultdict(int)

        # Initialize adjacency lists with self-loops
        for v in range(n):
            graph[v].append(v)

        # Build adjacency lists from edges
        for u, v in edges:
            graph[u].append(v)
            graph[v].append(u)

        # Count frequency of each unique adjacency pattern
        for v in range(n):
            neighbors = tuple(sorted(graph[v]))
            component_freq[neighbors] += 1

        # Count complete components where size equals frequency
        return sum(1 for neighbors, freq in component_freq.items() if len(neighbors) == freq)
