class Solution:
    def canConstruct(self, s: str, k: int) -> bool:
        # Base case 1
        if len(s) < k:
            return False

        # Base case 2
        if len(s) == k:
            return True

        # Initialize frequency dictionary and odd_count
        freq, odd_count = [0] * 26, 0
        
        # Increment the value of index corresponding to the current character
        for c in s:
            freq[ord(c) - 97] += 1
    
        # Count the number of characters appearing an odd number of times in s
        for count in freq:
            if count % 2:
                odd_count += 1
        
        # Return if the number of odd frequencies is less than or equal to k
        return odd_count <= k

        