class Solution:
    def maxProbability(self, n: int, edges: List[List[int]], succProb: List[float], start: int, end: int) -> float:
        graph = defaultdict(list)
        for i, (u, v) in enumerate(edges):
            graph[u].append((v, succProb[i]))
            graph[v].append((u, succProb[i]))
        
        max_prob = [0, 0] * n
        max_prob[start] = 1.0
        
        pq = [(-1.0, start)]
        
        while pq:
            curr_prob, curr_node = heappop(pq)
            if curr_node == end:
                return -curr_prob
            for next_node, path_prob in graph[curr_node]:
                if -curr_prob * path_prob > max_prob[next_node]:
                    max_prob[next_node] = -curr_prob * path_prob
                    heappush(pq, (-max_prob[next_node], next_node))
        
        return 0.0