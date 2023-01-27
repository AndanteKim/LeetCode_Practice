class Solution:
    def countElements(self, arr: List[int]) -> int:
        lookup = {num for num in arr}
        cnt = 0
        for num in arr:
            if num in lookup and num + 1 in lookup:
                cnt += 1
        return cnt