class Solution:
    def checkStraightLine(self, coordinates: List[List[int]]) -> bool:
        x_incre, y_incre = coordinates[1][0] - coordinates[0][0], coordinates[1][1] - coordinates[0][1]
        
        for i in range(2, len(coordinates)):
            if x_incre * (coordinates[i][1] - coordinates[i-1][1]) != y_incre * (coordinates[i][0] - coordinates[i-1][0]):
                return False
            
        return True