class Solution:
    INF = 2e9
    def modifiedGraphEdges(self, n: int, edges: List[List[int]], source: int, destination: int, target: int) -> List[List[int]]:
        graph = [[] for _ in range(n)]
        
        # Build the graph with known weights
        for u, v, w in edges:
            if w != -1:
                graph[u].append((v, w))
                graph[v].append((u, w))
                
        # Compute the initial shortest distance
        curr_shortest_dist = self._dijkstra(graph, source, destination)
        
        if curr_shortest_dist < target:
            return []
        
        if curr_shortest_dist == target:
            # Update edges with -1 weight to an impossible value
            for edge in edges:
                if edge[2] == -1:
                    edge[2] = self.INF
            return edges
        
        # Adjust edges with unknown weights
        for i, (u, v, w) in enumerate(edges):
            if w != -1:
                continue
                
            # Set edge weigh to 1 initially
            edges[i][2] = 1
            graph[u].append((v, 1))
            graph[v].append((u, 1))
            
            # Recompute shortest distance with updated edge weight
            new_dist = self._dijkstra(graph, source, destination)
            
            if new_dist <= target:
                edges[i][2] += target - new_dist
                
                # Update remaining edges with -1 weight to an impossible value
                for j in range(i + 1, len(edges)):
                    if edges[j][2] == -1:
                        edges[j][2] = self.INF
                return edges
        return []
    
    def _dijkstra(self, graph: List[List[Tuple[int, int]]], src: int, dst: int) -> int:
        min_dist = [self.INF] * len(graph)
        min_dist[src] = 0
        min_heap = [(0, src)] # (distance, node)
        
        while min_heap:
            d, u = heappop(min_heap)
            if d > min_dist[u]:
                continue
                
            for v, w in graph[u]:
                if d + w < min_dist[v]:
                    min_dist[v] = d + w
                    heappush(min_heap, (min_dist[v], v))
                    
        return min_dist[dst]