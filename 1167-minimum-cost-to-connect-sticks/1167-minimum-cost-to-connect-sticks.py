class Solution:
    def connectSticks(self, sticks: List[int]) -> int:
        if len(sticks) <= 1:
            return 0
        
        
        min_heap = []
        for n in sticks:
            heappush(min_heap, n)
        
        ans = 0
        while len(min_heap) > 1:
            connect = heappop(min_heap) + heappop(min_heap)
            ans += connect
            heappush(min_heap, connect)
        
        return ans