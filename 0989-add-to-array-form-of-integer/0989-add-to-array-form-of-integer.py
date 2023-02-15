class Solution:
    def addToArrayForm(self, num: List[int], k: int) -> List[int]:
        digits, total, ans = len(num) - 1, 0, []
        
        for i in range(digits, -1, -1):
            total += (num[digits - i] * (10 ** i))
        total += k
        
        while total:
            ans = [total % 10] + ans
            total //= 10
        
        return ans