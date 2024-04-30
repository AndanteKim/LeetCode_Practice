class Solution:
    def subsequenceSumOr(self, nums: List[int]) -> int:
        # Array to store the count of bits set at each position (0 to 63)
        bit_set_counts, ans = [0] * 64, 0
        
        # Loop through each number in the array
        for num in nums:
            # Loop through each bit position (0 to 30)
            # since the input numbers are in the range of int
            for i in range(31):
                # Check if the ith bit of current number is set
                if num & (1 << i):
                    # If yes, increment the count of set bits at that position
                    bit_set_counts[i] += 1
            
        # Loop through each bit position (0 to 62)
        # since we're calculating the OR of subsequences
        for i in range(63):
            # If there are any set bits at the current position
            if bit_set_counts[i] > 0:
                # Set the corresponding bit in the result
                ans |= 1 << i
            
            # Carry over any excess bits to the next position
            bit_set_counts[i + 1] += bit_set_counts[i] >> 1
            
        return ans
        
        