class Solution:
    def maxProbability(self, n: int, edges: List[List[int]], succProb: List[float], start: int, end: int) -> float:
        max_prob = [0] * n
        max_prob[start] = 1
        
        for i in range(n - 1):
            has_update = False
            for j in range(len(edges)):
                u, v = edges[j]
                path_prob = succProb[j]
                
                # find the maximum probability between (start, end)
                if max_prob[u] * path_prob > max_prob[v]:
                    max_prob[v] = max_prob[u] * path_prob
                    has_update = True
                if max_prob[v] * path_prob > max_prob[u]:
                    max_prob[u] = max_prob[v] * path_prob
                    has_update = True
            if not has_update:
                break
        
        return max_prob[end]