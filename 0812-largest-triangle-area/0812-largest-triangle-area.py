class Solution:
    def largestTriangleArea(self, points: List[List[int]]) -> float:
        def area(p: Tuple[int, int], q: Tuple[int, int], r: Tuple[int, int]) -> int:
            return 0.5 * abs(p[0] * q[1] + q[0] * r[1] + r[0] * p[1] - p[1] * q[0] - q[1] * r[0] - r[1] * p[0])

        return max(area(*triangle) for triangle in itertools.combinations(points, 3))