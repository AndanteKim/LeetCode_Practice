class Solution:
    def countMaxOrSubsets(self, nums: List[int]) -> int:
        def backtrack(i: int, curr_or: int, target_or: int) -> int:
            # Base case: Reached the end of the array
            if i == n:
                return 1 if curr_or == target_or else 0
            
            # Don't include the current number
            count_without = backtrack(i + 1, curr_or, target_or)
            
            # Include the current number
            count_with = backtrack(i + 1, curr_or | nums[i], target_or)
            
            # Return the sum of both cases
            return count_without + count_with
        
        maximum = 0
        
        for num in nums:
            maximum |= num
        
        n = len(nums)
        return backtrack(0, 0, maximum)