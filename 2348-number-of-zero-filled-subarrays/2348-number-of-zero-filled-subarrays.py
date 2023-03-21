class Solution:
    def zeroFilledSubarray(self, nums: List[int]) -> int:
        ans, num_subarray = 0, 0
        
        for num in nums:
            if num == 0:
                num_subarray += 1
            else:
                num_subarray = 0
            ans += num_subarray
        return ans