class Solution:
    def minNumberOfSeconds(self, mountainHeight: int, workerTimes: List[int]) -> int:
        min_heap = []

        for w in workerTimes:
            heappush(min_heap, (w, w * 2, w))
        
        for _ in range(mountainHeight):
            time, next_term, base = heappop(min_heap)
            heappush(min_heap, (time + next_term, next_term + base, base))
        
        return max(time - next_term + base for time, next_term, base in min_heap)