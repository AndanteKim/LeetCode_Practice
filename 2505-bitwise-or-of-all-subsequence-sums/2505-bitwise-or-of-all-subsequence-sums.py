class Solution:
    def subsequenceSumOr(self, nums: List[int]) -> int:
        ans, prefix_sum = 0, 0
        
        # Iterate through each element in the input array
        for num in nums:
            # Update the cumulative sum by adding the current element
            prefix_sum += num
            # Update the result by performing bitwise OR with the current element and the cumulative sum
            ans |= num | prefix_sum
        
        return ans