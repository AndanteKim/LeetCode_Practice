class Solution:
    def checkOverlap(self, radius: int, xCenter: int, yCenter: int, x1: int, y1: int, x2: int, y2: int) -> bool:
        dist = 0

        if xCenter < x1 or xCenter > x2:
            dist += min((x1 - xCenter) ** 2, (x2 - xCenter) ** 2)
        
        if yCenter < y1 or yCenter > y2:
            dist += min((y1 - yCenter) ** 2, (y2 - yCenter) ** 2)
        
        return dist <= radius ** 2
