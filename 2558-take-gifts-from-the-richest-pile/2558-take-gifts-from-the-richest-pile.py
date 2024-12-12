class Solution:
    def pickGifts(self, gifts: List[int], k: int) -> int:
        pq = [-gift for gift in gifts]
        heapify(pq)
        
        for _ in range(k):
            if pq:
                first = int((-heappop(pq)) ** 0.5)
                heappush(pq, -first)
        
        ans = 0
        while pq:
            ans += -heappop(pq)
        
        return ans