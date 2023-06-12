class Solution:
    def summaryRanges(self, nums: List[int]) -> List[str]:
        ans, n, i = [], len(nums), 0
        
        while i < n:
            start = nums[i]
            while i + 1 < n and nums[i] + 1 == nums[i + 1]:
                i += 1
            
            if start != nums[i]:
                ans.append(f'{start}->{nums[i]}')
            else:
                ans.append(f'{nums[i]}')
        
            i += 1
        
        return ans