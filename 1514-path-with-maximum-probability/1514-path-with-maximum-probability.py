class Solution:
    def maxProbability(self, n: int, edges: List[List[int]], succProb: List[float], start: int, end: int) -> float:
        graph = defaultdict(list)
        
        for i, (a, b) in enumerate(edges):
            graph[a].append([b, succProb[i]])
            graph[b].append([a, succProb[i]])
        
        max_prob = [0.0] * n
        max_prob[start] = 1.0
        
        queue = deque([start])
        while queue:
            curr_node = queue.popleft()
            for next_node, path_prob in graph[curr_node]:
                if max_prob[curr_node] * path_prob > max_prob[next_node]:
                    max_prob[next_node] = max_prob[curr_node] * path_prob
                    queue.append(next_node)
        
        return max_prob[end]