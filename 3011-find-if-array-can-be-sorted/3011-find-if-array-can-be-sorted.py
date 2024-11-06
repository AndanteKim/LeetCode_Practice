class Solution:
    def canSortArray(self, nums: List[int]) -> bool:
        n = len(nums)
        # Create a copy of the original array
        values = nums[:]
        
        # First Pass: Iterate from left to right
        # Goal: Move the maximum value of each segment as far right as possible.
        for i in range(n - 1):
            if values[i] <= values[i + 1]:
                continue
                
            # Check if the current and next element have the same number of set bits
            if bin(values[i]).count('1') == bin(values[i + 1]).count('1'):
                # Swap if they do
                values[i], values[i + 1] = values[i + 1], values[i]
            else:
                return False    # Return False if they cannot be swapped
            
        # Second Pass: Iterate from right to left
        # Goal: Move the minimum value of each segment as far left as possible
        for i in range(n - 1, 0, -1):
            if values[i] >= values[i - 1]:
                continue
                
            # Check if the current and previous element have the same number of set bits
            if bin(values[i]).count('1') == bin(values[i - 1]).count('1'):
                # Swap if they do
                values[i], values[i - 1] = values[i - 1], values[i]
            else:
                return False    # Return False if they cannot be swapped
            
        # If both passes complete without returning False, the arraay can be sorted.
        return True
                