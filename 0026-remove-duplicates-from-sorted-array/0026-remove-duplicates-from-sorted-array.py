class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        unique = []
        for num in nums:
            if not unique or unique[-1] != num:
                unique.append(num)
        
        for i in range(len(unique)):
            nums[i] = unique[i]
            
        return len(unique)
        