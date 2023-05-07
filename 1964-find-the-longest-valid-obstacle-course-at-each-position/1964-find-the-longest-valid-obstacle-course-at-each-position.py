class Solution:
    def longestObstacleCourseAtEachPosition(self, obstacles: List[int]) -> List[int]:
        n = len(obstacles)
        ans, lis = [1] * n, []
        
        for i in range(n):
            idx = bisect.bisect_right(lis, obstacles[i])
            
            if idx == len(lis):
                lis.append(obstacles[i])
            else:
                lis[idx] = obstacles[i]
            ans[i] = idx + 1
        
        return ans