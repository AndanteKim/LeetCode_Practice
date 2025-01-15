class Solution:
    def minimizeXor(self, num1: int, num2: int) -> int:
        # Initialize result to num1. We'll modify result.
        res = num1

        target_set_bits_count = bin(num2).count("1")
        set_bits_count = bin(res).count("1")

        # Start with the least significant bit (bit 0).
        curr_bit = 0

        # Add bits to result if it has fewer set bits than the target.
        while set_bits_count < target_set_bits_count:
            # If the current bit in result is not set (0), set it to 1.
            if not self._is_set(res, curr_bit):
                res = self._set_bit(res, curr_bit)
                set_bits_count += 1
            
            # Move to the next bit.
            curr_bit += 1
        
        # Remove bits from result if it has more set bits than the target.
        while set_bits_count > target_set_bits_count:
            # If the current bit in result is set (1), unset it (make it 0).
            if self._is_set(res, curr_bit):
                res = self._unset_bit(res, curr_bit)
                set_bits_count -= 1
            
            # Move to the next bit.
            curr_bit += 1

        return res

    # Helper function to check if the given bit position in result is set (1).
    def _is_set(self, x: int, bit: int) -> bool:
        return (x & (1 << bit)) != 0
    
    # Helper function to set the given bit position in result to 1.
    def _set_bit(self, x: int, bit: int) -> int:
        return x | (1 << bit)
    
    # Helper function to unset the given bit position in x (X set it to 0).
    def _unset_bit(self, x: int, bit: int) -> int:
        return x & ~(1 << bit)

