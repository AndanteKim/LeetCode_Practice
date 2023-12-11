class Solution:
    def findSpecialInteger(self, arr: List[int]) -> int:
        n, cnt, prev = len(arr), 0, -1
        
        for i in range(n):
            if prev == -1 or arr[i] == prev:
                cnt += 1
            else:
                cnt = 1
            prev = arr[i]
            if cnt / n > 0.25:
                return arr[i]
        return -1