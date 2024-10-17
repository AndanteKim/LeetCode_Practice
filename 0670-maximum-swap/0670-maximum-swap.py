class Solution:
    def maximumSwap(self, num: int) -> int:
        num_str = str(num)
        n = len(num_str)
        last_seen = [-1] * 10   # Store the last occurrence of each digit
        
        # Record the last occurrence of each digit
        for i in range(n):
            last_seen[int(num_str[i])] = i
            
        # Traverse the string to find the first digit that can be swapped with a larger one
        for i in range(n):
            for d in range(9, int(num_str[i]), - 1):
                if last_seen[d] > i:
                    # Perform the swap
                    num_str = list(num_str)
                    num_str[i], num_str[last_seen[d]] = num_str[last_seen[d]], num_str[i]
                    
                    # Return the new number immediately after the swap
                    return int("".join(num_str))
                
        return num  # Return the original number if no swap can maximize it.
        