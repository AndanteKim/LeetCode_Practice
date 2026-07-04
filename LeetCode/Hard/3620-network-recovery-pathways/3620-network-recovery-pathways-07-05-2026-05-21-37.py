class Solution:
    def findMaxPathScore(self, edges: List[List[int]], online: List[bool], k: int) -> int:
        def check(mid: int) -> bool:
            memo = [-1] * n

            def dfs(u: int) -> int:
                if u == n - 1:
                    return 0
                
                if memo[u] != -1:
                    return memo[u]
                
                ans = float("inf")
                for v, w in g[u]:
                    if w >= mid:
                        ans = min(ans, dfs(v) + w)
                
                memo[u] = ans
                return ans

            return dfs(0) <= k

        
        n = len(online)
        g = [[] for _ in range(n)]
        l, r = float('inf'), 0

        for u, v, w in edges:
            if not (online[v] and online[v]):
                continue
            g[u].append((v, w))
            l, r = min(l, w), max(r, w)

        if not check(l):
            return -1

        while l <= r:
            mid = (l + r) >> 1
            if check(mid):
                l = mid + 1
            else:
                r = mid - 1
        
        return r