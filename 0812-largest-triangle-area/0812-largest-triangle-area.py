class Solution:
    def largestTriangleArea(self, points: List[List[int]]) -> float:
        points.sort()
        ans, n = 0.0, len(points)
        height, width = defaultdict(list), defaultdict(list)

        for i in range(n):
            x, y = points[i]
            height[x].append(y)
            width[y].append(x)

        ans = 0
        for x, y_pts in height.items():
            if x in width:
                ans = max(ans, (width[x][-1] - width[x][0]) * (y_pts[-1] - y_pts[0]) / 2.0)

        return ans