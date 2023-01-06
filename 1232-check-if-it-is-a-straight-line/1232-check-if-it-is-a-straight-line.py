class Solution:
    def checkStraightLine(self, coordinates: List[List[int]]) -> bool:
        diff_x, diff_y = set(), set()
        for i in range(len(coordinates)):
            diff_x.add(coordinates[i][0])
            diff_y.add(coordinates[i][1])
        if len(diff_x) == 1 or len(diff_y) == 1:
            return True
        
        coordinates.sort(key = lambda x: (x[0], x[1]))
        try:
            slope = (coordinates[1][1] - coordinates[0][1])/(coordinates[1][0] - coordinates[0][0])
        except:
            return False
        
        for i in range(len(coordinates)-1):
            try:
                if slope != (coordinates[i+1][1] - coordinates[i][1])/(coordinates[i+1][0] - coordinates[i][0]):
                    return False
            except:
                return False
        return True