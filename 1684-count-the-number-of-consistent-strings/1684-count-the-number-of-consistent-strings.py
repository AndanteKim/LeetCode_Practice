class Solution:
    def countConsistentStrings(self, allowed: str, words: List[str]) -> int:
        # Create a bitmask representing the allowed characters
        allowed_bits, consistent_count = 0, 0
        
        # Set the corresponding bit for each character in allowed
        for c in allowed:
            allowed_bits |= (1 << (ord(c) - 97))
            
        # Iterate through each word in the words list
        for word in words:
            is_consistent = True
            
            # Check each character in the word
            for c in word:
                # Calculate the bit position for the current character
                bit = (allowed_bits >> (ord(c) - 97)) & 1
                
                # If the bit is 0, the character isn't allowed
                if not bit:
                    is_consistent = False
                    break
            
            # If the word is consistent, increment the count
            if is_consistent:
                consistent_count += 1
                
        return consistent_count