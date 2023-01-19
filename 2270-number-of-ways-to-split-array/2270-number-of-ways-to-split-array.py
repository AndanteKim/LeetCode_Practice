class Solution:
    def waysToSplitArray(self, nums: List[int]) -> int:
        prefix = [nums[0]]
        
        for i in range(1, len(nums)):
            prefix.append(prefix[-1] + nums[i])
        
        ans = 0
        
        for i in range(len(nums)-1):
            left_section = prefix[i]
            right_section = prefix[-1] - left_section
            if left_section >= right_section:
                ans += 1
        
        return ans