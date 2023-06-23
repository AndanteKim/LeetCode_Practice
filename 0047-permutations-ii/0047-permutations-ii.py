class Solution:
    def backtrack(self, start: int, nums: List[int], ans: List[List[int]]) -> None:
        if start == len(nums):
            ans.append(nums[:])
            return
        
        lookup = set()
        for i in range(start, len(nums)):
            if nums[i] not in lookup:
                nums[start], nums[i] = nums[i], nums[start]
                self.backtrack(start + 1, nums, ans)
                nums[start], nums[i] = nums[i], nums[start]
                lookup.add(nums[i])
    
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        ans = []
        self.backtrack(0, nums, ans)
        
        return ans