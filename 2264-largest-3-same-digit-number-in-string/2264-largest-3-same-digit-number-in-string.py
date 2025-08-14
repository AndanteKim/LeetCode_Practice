class Solution:
    def largestGoodInteger(self, num: str) -> str:
        n, candidates = len(num), []
        for i in range(n - 2):
            if num[i] == num[i + 1] == num[i + 2]:
                candidates.append(num[i] * 3)
        
        if len(candidates) == 0:
            return ''
        
        candidates.sort()
        return candidates[-1]