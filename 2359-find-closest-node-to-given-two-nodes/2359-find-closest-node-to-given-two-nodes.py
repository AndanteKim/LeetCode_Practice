class Solution:
    def closestMeetingNode(self, edges: List[int], node1: int, node2: int) -> int:
        def calc_dist(node):
            dist = defaultdict(lambda: -1)
            dist[node] = 0
            
            while edges[node] != -1 and dist[edges[node]] == -1:
                dist[edges[node]] = dist[node] + 1
                node = edges[node]
            return dist
        
        dist1, dist2 = calc_dist(node1), calc_dist(node2)
        min_dist = float('inf')
        res = - 1
        
        for n in range(len(edges)):
            max_dist = max(dist1[n], dist2[n])
            if dist1[n] != -1 and dist2[n] != -1 and min_dist > max_dist:
                min_dist = max_dist
                res = n
        return res