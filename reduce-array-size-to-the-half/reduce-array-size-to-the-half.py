class Solution:
    def minSetSize(self, arr: List[int]) -> int:
        frequencies = Counter(arr)
        freq, total = [], 0
        for key, val in frequencies.items():
            freq.append(val)
            total += val
        
        freq.sort()
        ans, n = 0, len(arr)
        
        while total > n // 2:
            total -= freq.pop()
            ans += 1
        
        return ans
        