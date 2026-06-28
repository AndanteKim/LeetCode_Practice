class Solution:
    def maximumElementAfterDecrementingAndRearranging(self, arr: List[int]) -> int:
        arr.sort()
        ans, prev = 0, 0

        for num in arr:
            if abs(num - prev) >= 1:
                num = prev + 1
                prev = num
            ans = max(ans, num)
            
        return ans