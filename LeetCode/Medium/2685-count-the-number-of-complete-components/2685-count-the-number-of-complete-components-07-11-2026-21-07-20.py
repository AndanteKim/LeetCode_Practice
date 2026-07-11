class UnionFind:
    def __init__(self, n: int):
        self.parent = [-1] * n
        self.size = [1] * n

    def _find(self, node: int) -> int:
        if self.parent[node] == -1:
            return node
        
        self.parent[node] = self._find(self.parent[node])
        return self.parent[node]
    
    def _union(self, node1: int, node2: int) -> None:
        root1, root2 = self._find(node1), self._find(node2)

        if root1 == root2:
            return
        
        if self.size[root1] > self.size[root2]:
            self.parent[root2] = root1
            self.size[root1] += self.size[root2]
        else:
            self.parent[root1] = root2
            self.size[root2] += self.size[root1]

class Solution:
    def countCompleteComponents(self, n: int, edges: List[List[int]]) -> int:
        dsu = UnionFind(n)
        edge_cnt = dict()

        for u, v in edges:
            dsu._union(u, v)
        
        for u, v in edges:
            root = dsu._find(u)
            edge_cnt[root] = edge_cnt.get(root, 0) + 1
        
        complete_cnt = 0
        for v in range(n):
            if dsu._find(v) == v:
                node_cnt = dsu.size[v]
                expected = (node_cnt * (node_cnt - 1)) >> 1
                if edge_cnt.get(v, 0) == expected:
                    complete_cnt += 1

        return complete_cnt
