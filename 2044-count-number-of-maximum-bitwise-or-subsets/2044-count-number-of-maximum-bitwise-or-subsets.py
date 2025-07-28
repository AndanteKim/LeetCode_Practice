class Solution:
    def countMaxOrSubsets(self, nums: List[int]) -> int:
        def backtrack(i: int, curr: int) -> None:
            if i == n:
                if curr == max_num:
                    self.ans += 1
                return
            
            backtrack(i + 1, curr)
            backtrack(i + 1, curr | nums[i])
        
        max_num = 0
        for num in nums:
            max_num |= num

        self.ans, n = 0, len(nums)
        backtrack(0, 0)

        return self.ans