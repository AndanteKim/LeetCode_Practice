class Solution:
    def mostCompetitive(self, nums: List[int], k: int) -> List[int]:
        stack = []
        
        for i in range(len(nums)):
            min_stack_len = max(0, k - len(nums) + i)
            while len(stack) > min_stack_len and nums[i] < stack[-1]:
                stack.pop()
            stack.append(nums[i])
            
        return stack[:k]