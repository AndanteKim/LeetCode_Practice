class Solution:
    def findClosestElements(self, arr: List[int], k: int, x: int) -> List[int]:
        arr.sort(key = lambda val: abs(val - x))
        arr = arr[:k]
        arr.sort()
        return arr