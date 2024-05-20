class Solution:
    def subsetXORSum(self, nums: List[int]) -> int:
        def backtrack(i: int, curr: int) -> None:
            nonlocal ans
            if i == n:
                ans += curr
                return
            
            backtrack(i + 1, curr ^ nums[i])
            backtrack(i + 1, curr)
            
        
        n, ans = len(nums), 0
        backtrack(0, 0)
        
        return ans