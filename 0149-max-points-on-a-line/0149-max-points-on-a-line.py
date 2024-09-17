class Solution:
    def calculate_slope(self, p1: List[int], p2: List[int]) -> float:
        x1, x2 = p1[0], p2[0]
        y1, y2 = p1[1], p2[1]
        
        if x1 == x2:
            return float('inf')
        if y1 == y2:
            return 0
        
        return (float) (y2 - y1) / (x2 - x1)
    
    def maxPoints(self, points: List[List[int]]) -> int:
        # Geometry + hash map
        n = len(points)
        if n == 1:
            return 1
        
        ans = 0
        
        for i in range(n):
            count = defaultdict(int)
            for j in range(i + 1, n):
                slope = self.calculate_slope(points[i], points[j])
                count[slope] += 1
                ans = max(ans, count[slope])
                
        # Since points[i] also lies on the line
        return ans + 1