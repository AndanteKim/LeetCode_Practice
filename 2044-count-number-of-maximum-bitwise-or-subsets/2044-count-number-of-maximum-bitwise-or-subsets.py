class Solution:
    def countMaxOrSubsets(self, nums: List[int]) -> int:
        def backtrack(i: int, curr_or:int, target_or: int) -> int:
            # Base case: Reached the end of the array
            if i == n:
                return 1 if curr_or == target_or else 0
            
            # Check if the result for this state is already memoized
            if memo[i][curr_or] != -1:
                return memo[i][curr_or]
            
            # Don't include the current number
            count_without = backtrack(i + 1, curr_or, target_or)
            
            # Include the current number
            count_with = backtrack(i + 1, curr_or | nums[i], target_or)
            
            # Memoize and return the result
            memo[i][curr_or] = count_without + count_with
            return memo[i][curr_or]
        
        max_or_val = 0
        
        # Caculate the maximum OR value
        for num in nums:
            max_or_val |= num
            
        n = len(nums)
        
        # Initialize memo with -1
        memo = [[-1] * (max_or_val + 1) for _ in range(n)]
        return backtrack(0, 0, max_or_val)