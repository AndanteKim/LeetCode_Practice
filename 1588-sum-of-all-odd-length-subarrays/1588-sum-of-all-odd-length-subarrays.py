class Solution:
    def sumOddLengthSubarrays(self, arr: List[int]) -> int:
        ans, n = 0, len(arr)
        
        for i, a in enumerate(arr):
            left, right = i, n - i - 1
            ans += a * (left // 2 + 1) * (right // 2 + 1)
            ans += a * ((left + 1) // 2) * ((right + 1) // 2)
            
        return ans
            