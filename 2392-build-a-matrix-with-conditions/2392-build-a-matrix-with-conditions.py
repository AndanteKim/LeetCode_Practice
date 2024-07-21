class Solution:
    def __topo_sort(self, edges: List[List[int]], n: int) -> List[int]:
        adj, order = [[] for _ in range(n + 1)], []
        deg = [0] * (n + 1)
        
        for x in edges:
            adj[x[0]].append(x[1])
            deg[x[1]] += 1
        
        q = deque()
        
        for i in range(1, n + 1):
            if deg[i] == 0:
                q.append(i)
                
        while q:
            f = q.popleft()
            order.append(f)
            n -= 1
            
            for v in adj[f]:
                deg[v] -= 1
                if deg[v] == 0:
                    q.append(v)
        
        return [] if n != 0 else order
        
    
    def buildMatrix(self, k: int, rowConditions: List[List[int]], colConditions: List[List[int]]) -> List[List[int]]:
        order_rows = self.__topo_sort(rowConditions, k)
        order_cols = self.__topo_sort(colConditions, k)
        
        if not (order_rows and order_cols):
            return []
        
        matrix = [[0] * k for _ in range(k)]
        for i in range(k):
            for j in range(k):
                if order_rows[i] == order_cols[j]:
                    matrix[i][j] = order_rows[i]
                    
        return matrix
        
        