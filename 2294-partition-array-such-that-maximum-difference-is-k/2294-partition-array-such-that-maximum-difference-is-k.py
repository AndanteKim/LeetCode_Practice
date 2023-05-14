class Solution:
    def partitionArray(self, nums: List[int], k: int) -> int:
        nums.sort()
        ans, prev = 1, nums[-1]
        while nums:
            num = nums.pop()
            if prev - num > k:
                ans += 1
                prev = num
        return ans
            
        