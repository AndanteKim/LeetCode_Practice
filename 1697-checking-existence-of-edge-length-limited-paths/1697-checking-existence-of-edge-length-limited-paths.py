class UnionFind:
    def __init__(self, size: int):
        self.parent, self.rank = [i for i in range(size)], [0] * size
        
    def find(self, x: int) -> int:
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]
    
    def union_set(self, x: int, y: int) -> None:
        xset, yset = self.find(x), self.find(y)
        
        if xset == yset:
            return
        
        if self.rank[xset] > self.rank[yset]:
            self.parent[yset] = xset
        elif self.rank[xset] < self.rank[yset]:
            self.parent[xset] = yset
        else:
            self.parent[xset] = yset
            self.rank[yset] += 1
    
    def are_connected(self, x: int, y: int) -> bool:
        return self.find(x) == self.find(y)

class Solution:
    def distanceLimitedPathsExist(self, n: int, edgeList: List[List[int]], queries: List[List[int]]) -> List[bool]:
        uf = UnionFind(n)
        queries_count = len(queries)
        ans = [False] * queries_count
        
        queries_with_index = [[] for _ in range(queries_count)]
        for i in range(queries_count):
            queries_with_index[i] = queries[i]
            queries_with_index[i].append(i)
        
        edgeList.sort(key = lambda x: x[2])
        queries_with_index.sort(key = lambda x: x[2])
        edges_index = 0
        
        for [p, q, limit, query_original_index] in queries_with_index:
            while edges_index < len(edgeList) and edgeList[edges_index][2] < limit:
                node1, node2 = edgeList[edges_index][0], edgeList[edges_index][1]
                uf.union_set(node1, node2)
                edges_index += 1
            
            ans[query_original_index] = uf.are_connected(p, q)
        return ans