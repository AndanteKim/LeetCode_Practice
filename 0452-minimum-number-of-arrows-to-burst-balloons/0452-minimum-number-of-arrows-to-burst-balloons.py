class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        points.sort(key = lambda x: x[1])
        ans, curr_point = 0, float('-inf')
        print(points)

        for start, end in points:
            if curr_point < start:
                ans += 1
                curr_point = end
                
                
        return ans
        