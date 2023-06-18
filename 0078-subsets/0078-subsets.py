class Solution:
    def backtrack(self, size: int, curr: List[int], nums: List[int], ans: List[List[int]]) -> None:
        if size > len(nums):
            return
        
        ans.append(curr[:])
        for i in range(size, len(nums)):
            curr.append(nums[i])
            self.backtrack(i + 1, curr, nums, ans)
            curr.pop()
    
    def subsets(self, nums: List[int]) -> List[List[int]]:
        ans, n = [], len(nums)
        self.backtrack(0, [], nums, ans)
        
        return ans