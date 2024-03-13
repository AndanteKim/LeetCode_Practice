class Solution:
    def pivotInteger(self, n: int) -> int:
        s = (n * (n + 1) >> 1)
        pivot = int(s ** 0.5)
        
        # If pivot * pivot is equal to sum (pivot found) return pivot, else return -1
        return pivot if pivot * pivot == s else -1