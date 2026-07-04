class Solution:
    def findMaxPathScore(self, edges: List[List[int]], online: List[bool], k: int) -> int:
        def check(mid: int) -> bool:
            dist = [float('inf')] * n
            pq = [(0, 0)]
            dist[0] = 0

            while pq:
                d, u = heappop(pq)

                if d > k:
                    return False
                
                if u == n - 1:
                    return True
                
                if d > dist[u]:
                    continue
                
                for v, w in graph[u]:
                    if w < mid:
                        continue

                    if dist[v] > dist[u] + w:
                        dist[v] = dist[u] + w
                        heappush(pq, (dist[v], v))

            return False 
        
        n = len(online)
        graph = [[] for _ in range(n)]
        l, r = float('inf'), 0

        for u, v, w in edges:
            if not (online[u] and online[v]):
                continue
            graph[u].append((v, w))
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