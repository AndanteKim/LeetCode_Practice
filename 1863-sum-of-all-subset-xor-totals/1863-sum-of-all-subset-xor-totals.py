class Solution:
    def subsetXORSum(self, nums: List[int]) -> int:
        def generate_subsets(i: int, curr_xor: int) -> int:
            # Return current_xor when all elements in nums are already considered
            if i == n:
                return curr_xor
            
            # Calculate sum of subset with current element
            with_element = generate_subsets(i + 1, curr_xor ^ nums[i])
            
            # Calculate sum of subset without current element
            without_element = generate_subsets(i + 1, curr_xor)
        
            # Return sum of xor totals
            return with_element + without_element
        
        n = len(nums)
        return generate_subsets(0, 0)