class Solution:
    def minCostConnectPoints(self, points: List[List[int]]) -> int:
        n = len(points)
        mst_cost, edges_used = 0, 0
        
        # Track nodes which are visited
        in_mst = [False] * n
        
        min_dist = [float('inf')] * n
        min_dist[0] = 0
        
        while edges_used < n:
            curr_min_edge = float('inf')
            curr_node = -1
            
            # pick least weight node which is not in MST
            for node in range(n):
                if not in_mst[node] and curr_min_edge > min_dist[node]:
                    curr_min_edge = min_dist[node]
                    curr_node = node
                
            mst_cost += curr_min_edge
            edges_used += 1
            in_mst[curr_node] = True
            
            # Update adjacent nodes of current node
            for next_node in range(n):
                weight = abs(points[curr_node][0] - points[next_node][0]) + abs(points[curr_node][1] - points[next_node][1])
                
                if not in_mst[next_node] and min_dist[next_node] > weight:
                    min_dist[next_node] = weight
            
        return mst_cost