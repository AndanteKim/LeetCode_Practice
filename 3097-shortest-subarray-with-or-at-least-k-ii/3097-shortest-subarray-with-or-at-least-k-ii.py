class Solution:
    def minimumSubarrayLength(self, nums: List[int], k: int) -> int:
        min_length, n, left, ans = float('inf'), len(nums), 0, float('inf')
        bit_counts = [0] * 32   # Tracks count of set bits at each position
        
        # Expand window until end of array
        for right in range(n):
            # Add current number to window
            self._update_bit_counts(bit_counts, nums[right], 1)
            
            # Contract window while OR value is valid
            while left <= right and self._convert_bits_to_num(bit_counts) >= k:
                # Update minimum length found so far
                ans = min(ans, right - left + 1)
                
                # Remove leftmost number and shrink window
                self._update_bit_counts(bit_counts, nums[left], -1)
                left += 1
        
        return -1 if ans == float('inf') else ans
    
    def _update_bit_counts(self, bit_counts: List[int], num: int, delta: int) -> None:
        # Update counts for each set bit in the number
        for pos in range(32):
            if num & (1 << pos):
                bit_counts[pos] += delta
                
    def _convert_bits_to_num(self, bit_counts: List[int]) -> int:
        # Convert bit counts to number using OR operation
        res = 0
        for i in range(32):
            if bit_counts[i]:
                res |= (1 << i)
                
        return res
    