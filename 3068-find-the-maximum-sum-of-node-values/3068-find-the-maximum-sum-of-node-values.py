class Solution:
    def maximumValueSum(self, nums: List[int], k: int, edges: List[List[int]]) -> int:
        def max_sum_of_nodes(i: int, is_even: int) -> int:
            if i == n:
                # If the operation is performed on an odd number of elements 
                return 0 if is_even else float('-inf')
            
            if memo[i][is_even] != -1:
                return memo[i][is_even]
            
            # Xor is applied on the element
            no_xor_done = nums[i] + max_sum_of_nodes(i + 1, is_even)
            
            # Xor is perfomed on the element
            xor_done = (nums[i] ^ k) + max_sum_of_nodes(i + 1, is_even ^ 1)
            
            # Memoize and return the result
            memo[i][is_even] = max(no_xor_done, xor_done)
            return memo[i][is_even]
        
        n = len(nums)
        memo = [[-1] * 2 for _ in range(n)]
        
        return max_sum_of_nodes(0, 1)