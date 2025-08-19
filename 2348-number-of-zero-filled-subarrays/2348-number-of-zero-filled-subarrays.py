class Solution:
    def zeroFilledSubarray(self, nums: List[int]) -> int:
        ans, count = 0, 0

        for num in nums:
            if num == 0:
                count += 1
            else:
                ans += (count * (count + 1) >> 1)
                count = 0
        
        if count != 0:
            ans += (count * (count + 1) >> 1)
        
        return ans