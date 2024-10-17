class Solution:
    def maximumSwap(self, num: int) -> int:
        num_str = list(str(num))
        n = len(num_str)
        max_digit_idx, swap_idx1, swap_idx2 = -1, -1, -1
        
        # Traverse the string from right to left, tracking the max digit and
        # potential swap
        for i in range(n - 1, -1, -1):
            if max_digit_idx == -1 or num_str[i] > num_str[max_digit_idx]:
                max_digit_idx = i   # Update the index of the max digit
            elif num_str[i] < num_str[max_digit_idx]:
                swap_idx1 = i   # Mark the index of the max digit
                swap_idx2 = max_digit_idx   # Mark the larger digit for swapping
                
        # Perform the sap if a valid swap is found.
        if swap_idx1 != -1 and swap_idx2 != -1:
            num_str[swap_idx1], num_str[swap_idx2] = num_str[swap_idx2], num_str[swap_idx1]
            
        # Return the new number or the original if no swap occurred
        return int("".join(num_str))