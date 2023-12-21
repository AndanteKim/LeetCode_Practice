class Solution:
    def maxWidthOfVerticalArea(self, points: List[List[int]]) -> int:
        width_points, width_visited, ans = [], set(), 0
        
        for point in points:
            if point[0] in width_visited:
                continue
            width_points.append(point[0])

        width_points.sort()
        current = width_points.pop()
        
        while width_points:
            nxt = width_points.pop()
            ans = max(ans, current - nxt)
            current = nxt
        
        return ans