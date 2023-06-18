class Solution:
    def backtrack(self, start: int, length: int, nums: List[int], ans: List[List[int]]) -> None:
        if start == length:
            ans.append(nums[:])
            return
        
        for i in range(start, length):
            nums[start], nums[i] = nums[i], nums[start]
            self.backtrack(start + 1, length, nums, ans)
            nums[start], nums[i] = nums[i], nums[start]
    
    def permute(self, nums: List[int]) -> List[List[int]]:
        n, ans = len(nums), []
        self.backtrack(0, n, nums, ans)
        return ans