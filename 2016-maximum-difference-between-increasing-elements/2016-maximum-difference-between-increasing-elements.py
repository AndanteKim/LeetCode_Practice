class Solution:
    def maximumDifference(self, nums: List[int]) -> int:
        ans, increasing = -1, []

        for num in nums:
            while increasing and increasing[-1] > num:
                increasing.pop()

            if increasing and num > increasing[0]:
                ans = max(ans, num - increasing[0])
            increasing.append(num)
            
        return ans