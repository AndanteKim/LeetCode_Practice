class Solution:
    def backtrack(self, curr: List[int], ans: List[List[int]], nums: List[int]) -> None:
        if len(curr) == len(nums):
            ans.append(curr[:])
            return
        
        for num in nums:
            if num not in curr:
                curr.append(num)
                self.backtrack(curr, ans, nums)
                curr.pop()
        
    
    def permute(self, nums: List[int]) -> List[List[int]]:
        ans = []
        self.backtrack([], ans, nums)
        
        return ans