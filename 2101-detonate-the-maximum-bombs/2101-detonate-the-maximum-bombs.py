class Solution:
    def maximumDetonation(self, bombs: List[List[int]]) -> int:
        adj = defaultdict(lambda: [])
        bombs.sort(key = lambda x: x[2])
        n = len(bombs)
        
        for i in range(n - 1):
            for j in range(i + 1, n):
                x1, y1, r1 = bombs[i]
                x2, y2, r2 = bombs[j]
                d = ((x2 - x1) ** 2 + (y2 - y1) ** 2) ** 0.5
                if d <= r1:
                    adj[i].append(j)
                if d <= r2:
                    adj[j].append(i)
        
        ans, d = 0, set()
        for b0 in range(len(bombs)):
            if b0 in d:
                continue
            
            if len(d) == n:
                continue
            
            queue, v = deque([b0]), set([b0])
            
            while queue:
                b1 = queue.popleft()
                d.add(b1)
                for b2 in adj[b1]:
                    if b2 not in v:
                        v.add(b2)
                        queue.append(b2)
            ans = max(ans, len(v))
        return ans
            
        
            