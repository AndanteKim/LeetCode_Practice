class Solution:
    def carPooling(self, trips: List[List[int]], capacity: int) -> bool:
        for i, v in sorted(x for n, i, j in trips for x in [[i, n], [j, -n]]):
            capacity -= v
            if capacity < 0:
                return False
            
        return True