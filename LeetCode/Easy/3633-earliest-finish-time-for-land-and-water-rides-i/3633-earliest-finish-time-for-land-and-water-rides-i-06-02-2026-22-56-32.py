class Solution:
    def earliestFinishTime(self, landStartTime: List[int], landDuration: List[int], waterStartTime: List[int], waterDuration: List[int]) -> int:
        ans, m, n = float('inf'), len(landStartTime), len(waterStartTime)
        for i in range(m):
            elapsed = landStartTime[i] + landDuration[i]
            for j in range(n):
                curr = max(elapsed, waterStartTime[j]) + waterDuration[j]
            
                ans = min(ans, curr)

        for j in range(n):
            elapsed = waterStartTime[j] + waterDuration[j]
            for i in range(m):
                curr = max(elapsed, landStartTime[i]) + landDuration[i]
                ans = min(ans, curr)
        
        return ans