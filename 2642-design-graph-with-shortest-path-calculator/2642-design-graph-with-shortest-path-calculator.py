class Graph:

    def __init__(self, n: int, edges: List[List[int]]):
        self.adj_matrix = [[float('inf')] * n for _ in range(n)]
        for start, end, cost in edges:
            self.adj_matrix[start][end] = cost
        
        for i in range(n):
            self.adj_matrix[i][i] = 0
        
        for i in range(n):
            for j in range(n):
                for k in range(n):
                    self.adj_matrix[j][k] = min(self.adj_matrix[j][k], \
                                               self.adj_matrix[j][i] +\
                                               self.adj_matrix[i][k])
                    
    def addEdge(self, edge: List[int]) -> None:
        start, end, cost = edge
        n = len(self.adj_matrix)
        for i in range(n):
            for j in range(n):
                self.adj_matrix[i][j] = min(self.adj_matrix[i][j],\
                                           self.adj_matrix[i][start] +\
                                           self.adj_matrix[end][j] + cost)

    def shortestPath(self, node1: int, node2: int) -> int:
        return -1 if self.adj_matrix[node1][node2] == float('inf') else self.adj_matrix[node1][node2]


# Your Graph object will be instantiated and called as such:
# obj = Graph(n, edges)
# obj.addEdge(edge)
# param_2 = obj.shortestPath(node1,node2)