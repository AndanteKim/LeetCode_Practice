class Solution:
    def numberOfArrays(self, differences: List[int], lower: int, upper: int) -> int:
        x = y = curr = 0
        for d in differences:
            curr += d
            x = min(x, curr)
            y = max(y, curr)
            if y - x > upper - lower:
                return 0

        return (upper - lower) - (y - x) + 1