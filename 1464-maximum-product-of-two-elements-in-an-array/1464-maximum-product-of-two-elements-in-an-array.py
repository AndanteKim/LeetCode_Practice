class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        counting, i = [0] * (10 ** 3 + 1), float('-inf')
        for num in nums:
            counting[num] += 1
            i = max(i, num)
        
        ans, remain = 1, 2
        while i >= 0 and remain > 0:
            if counting[i] > 0:
                counting[i] -= 1
                ans *= i - 1
                remain -= 1
            else:
                i -= 1
        return ans