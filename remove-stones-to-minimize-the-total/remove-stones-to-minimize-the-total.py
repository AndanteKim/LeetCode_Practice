class Solution:
    def minStoneSum(self, piles: List[int], k: int) -> int:
        pq = []
        for pile in piles:
            heappush(pq, -pile)
        
        for i in range(k):
            stone = -heappop(pq)
            if stone % 2 == 0:
                stone //= 2
            else:
                stone = stone // 2 + 1
            heappush(pq, -stone)
        return -sum(pq)