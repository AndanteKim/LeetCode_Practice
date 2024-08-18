class Solution:
    def nthUglyNumber(self, n: int) -> int:
        pq, multiplies, seen = [1], (2, 3, 5), {1}
        
        for i in range(n):
            min_n = heappop(pq)
            
            for multiply in multiplies:
                nxt = min_n * multiply
                
                if nxt not in seen:
                    heappush(pq, nxt)
                    seen.add(nxt)
        return min_n