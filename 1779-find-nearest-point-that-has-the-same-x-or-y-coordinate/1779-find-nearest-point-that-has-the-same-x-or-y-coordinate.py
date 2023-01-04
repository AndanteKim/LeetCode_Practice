class Solution:
    def nearestValidPoint(self, x: int, y: int, points: List[List[int]]) -> int:
        ans, current = -1, float("inf")
        for idx, point in enumerate(points):
            if x == point[0] or y == point[1]:
                if current > abs(x - point[0]) + abs(y - point[1]):
                    current = abs(x - point[0]) + abs(y - point[1])
                    ans = idx
                
        return ans