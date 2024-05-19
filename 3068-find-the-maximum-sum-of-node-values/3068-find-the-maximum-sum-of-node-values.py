class Solution:
    def maximumValueSum(self, nums: List[int], k: int, edges: List[List[int]]) -> int:
        @lru_cache(maxsize = None)
        def max_sum_of_nodes(i: int, is_even: int) -> int:
            if i == n:
                # If the operation is performed on an odd number of elements return float('-inf')
                return 0 if is_even == 1 else float('-inf')
            
            # No operation performed on the element
            no_xor = nums[i] + max_sum_of_nodes(i + 1, is_even)
            xor = (nums[i] ^ k) + max_sum_of_nodes(i + 1, is_even ^ 1)
            
            return max(no_xor, xor)
        
        n = len(nums)
        return max_sum_of_nodes(0, 1)