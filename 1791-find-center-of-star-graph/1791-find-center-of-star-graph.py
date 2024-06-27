class Solution:
    def findCenter(self, edges: List[List[int]]) -> int:
        graph = defaultdict(int)
        
        # edge = n - 1
        for start, end in edges:
            graph[start] += 1
            graph[end] += 1
        
        return max(graph, key = graph.get)