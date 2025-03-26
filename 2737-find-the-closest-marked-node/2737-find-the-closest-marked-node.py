class Solution:
    def minimumDistance(self, n: int, edges: List[List[int]], s: int, marked: List[int]) -> int:
        graph = defaultdict(list)

        for u, v, w in edges:
            graph[u].append((v, w))

        min_dists = [float('inf')] * n
        min_heap = [(0, s)]

        while min_heap:
            curr_dist, curr_node = heappop(min_heap)

            if curr_dist > min_dists[curr_node]:
                continue
            
            min_dists[curr_node] = curr_dist

            for neighbor, weight in graph[curr_node]:
                heappush(min_heap, (curr_dist + weight, neighbor))

        unknown_cnt = 0
        for node in marked:
            if min_dists[node] == float('inf'):
                unknown_cnt += 1
        
        return -1 if unknown_cnt == len(marked) else min(min_dists[node] for node in marked)