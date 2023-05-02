class Solution:
    def connectSticks(self, sticks: List[int]) -> int:
        heapify(sticks)
        ans = 0
        while len(sticks) > 1:
            curr = 0
            curr += heappop(sticks)
            curr += heappop(sticks)
            ans += curr
            heappush(sticks, curr)
            
        return ans
            