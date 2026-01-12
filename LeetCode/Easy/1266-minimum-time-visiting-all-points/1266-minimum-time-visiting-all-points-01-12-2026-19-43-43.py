class Solution:
    def minTimeToVisitAllPoints(self, points: List[List[int]]) -> int:
        ans, m = 0, len(points)

        for i in range(1, m):
            curr_x, curr_y = points[i - 1]
            next_x, next_y = points[i]
            dist = abs(curr_x - next_x) + abs(curr_y - next_y)
            diagonal = min(abs(curr_x - next_x), abs(curr_y - next_y))
            ans += dist - diagonal

        return ans