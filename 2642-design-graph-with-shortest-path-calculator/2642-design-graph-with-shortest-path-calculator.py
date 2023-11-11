class Graph:

    def __init__(self, n: int, edges: List[List[int]]):
        self.graph = [[] for _ in range(n)]
        
        for start, end, cost in edges:
            self.graph[start].append((end, cost))

    def addEdge(self, edge: List[int]) -> None:
        start, end, cost = edge
        self.graph[start].append((end, cost))

    def shortestPath(self, node1: int, node2: int) -> int:
        n, pq = len(self.graph), [(0, node1)]
        cost_for_node = [float('inf')] * n
        cost_for_node[node1] = 0
        
        while pq:
            curr_cost, curr_node = heappop(pq)
            if curr_cost > cost_for_node[curr_node]:
                continue
            
            if curr_node == node2:
                return curr_cost
            
            for neighbor, cost in self.graph[curr_node]:
                new_cost = curr_cost + cost
                if new_cost < cost_for_node[neighbor]:
                    cost_for_node[neighbor] = new_cost
                    heappush(pq, (new_cost, neighbor))
        
        return -1


# Your Graph object will be instantiated and called as such:
# obj = Graph(n, edges)
# obj.addEdge(edge)
# param_2 = obj.shortestPath(node1,node2)