class Solution:
    def remove_stale(self, pq: List[Tuple], left: int) -> int:
        while pq and pq[0][1] <= left:
            heappop(pq)
        return -pq[0][0] if pq else 0
    
    def maximumRobots(self, chargeTimes: List[int], runningCosts: List[int], budget: int) -> int:
        ans, total_run, left, pq = 0, 0, -1, []
        
        for right in range(len(runningCosts)):
            total_run += runningCosts[right]
            
            heappush(pq, (-chargeTimes[right], right))
            
            while total_run * (right - left) + self.remove_stale(pq, left) > budget:
                left += 1
                total_run -= runningCosts[left]
            ans = max(ans, right - left)
        return ans