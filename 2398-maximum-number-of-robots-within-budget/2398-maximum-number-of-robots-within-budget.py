class Solution:
    def maximumRobots(self, chargeTimes: List[int], runningCosts: List[int], budget: int) -> int:
        curr = left = 0
        n, dq = len(chargeTimes), deque()
        
        for right in range(n):
            curr += runningCosts[right]
            while dq and chargeTimes[dq[-1]] <= chargeTimes[right]:
                dq.pop()
            
            dq.append(right)
            
            if chargeTimes[dq[0]] + (right - left + 1) * curr > budget:
                if dq[0] == left:
                    dq.popleft()
                curr -= runningCosts[left]
                left += 1
        return n - left