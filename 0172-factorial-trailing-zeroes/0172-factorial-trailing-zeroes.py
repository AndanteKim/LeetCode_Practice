class Solution:
    def trailingZeroes(self, n: int) -> int:
        zero_count, curr_multiple = 0, 5
        
        while n >= curr_multiple:
            zero_count += n // curr_multiple
            curr_multiple *= 5
            
        return zero_count