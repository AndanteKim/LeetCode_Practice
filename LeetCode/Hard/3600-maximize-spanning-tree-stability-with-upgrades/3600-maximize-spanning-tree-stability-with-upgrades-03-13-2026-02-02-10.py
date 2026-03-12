class DSU:
    def __init__(self, parent: List[int]):
        self.parent = parent
    
    def find(self, x: int) -> int:
        if self.parent[x] == x:
            return x
        self.parent[x] = self.find(self.parent[x])
        return self.parent[x]

    def join(self, x: int, y: int) -> None:
        px, py = self.find(x), self.find(y)
        self.parent[px] = py

class Solution:
    def maxStability(self, n: int, edges: List[List[int]], k: int) -> int:
        ans = -1

        if len(edges) < n - 1:
            return -1
        
        must_edges = [e for e in edges if e[3] == 1]
        optional_edges = [e for e in edges if e[3] != 1]

        if len(must_edges) > n - 1:
            return -1
        
        optional_edges.sort(key = lambda x: x[2], reverse = True)

        selected_init = 0
        must_min_stability = 200_000
        dsu_init = DSU(list(range(n)))

        for u, v, s, must in must_edges:
            if dsu_init.find(u) == dsu_init.find(v) or selected_init == n - 1:
                return -1
            
            dsu_init.join(u, v)
            selected_init += 1
            must_min_stability = min(must_min_stability, s)

        l, r = 0, must_min_stability
        while l < r:
            mid = l + ((r - l + 1) >> 1)
            dsu = DSU(dsu_init.parent[:])
            selected = selected_init
            double_cnt = 0

            for u, v, s, must in optional_edges:
                if dsu.find(u) == dsu.find(v):
                    continue
                
                if s >= mid:
                    dsu.join(u, v)
                    selected += 1
                elif double_cnt < k and s * 2 >= mid:
                    double_cnt += 1
                    dsu.join(u, v)
                    selected += 1
                else:
                    break
                
                if selected == n - 1:
                    break
            
            if selected != n - 1:
                r = mid - 1
            else:
                ans = l = mid

        return ans
