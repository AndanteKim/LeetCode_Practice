class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        ans, n = [], len(nums)
        def backtrack(idx: int, curr: List[int]) -> None:
            if len(curr) == n:
                ans.append(curr[:])
                return
            
            for i in range(n):
                if nums[i] not in curr:
                    curr.append(nums[i])
                    backtrack(i + 1, curr)
                    curr.pop()
        
        backtrack(0, [])
        return ans