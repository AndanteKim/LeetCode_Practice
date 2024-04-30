class Solution:
    def wonderfulSubstrings(self, word: str) -> int:
        # Create the frequency map
        # key = bitmask, value = frequency of bitmask key
        freq = dict()
        # The empty prefix can be the smaller prefix, which is handled like this
        freq[0] = 1
        mask, ans = 0, 0
        
        for c in word:
            bit = ord(c) - 97
            
            # Flip the parity of the c-th bit in the running prefix mask
            mask ^= (1 << bit)
            
            # Count smaller prefixes creating substrings with no odd occurring letters
            if mask in freq:
                ans += freq[mask]
                freq[mask] += 1
            else:
                freq[mask] = 1
        
            # Loop through every possible letter that can appear an odd number of times in a substring
            for odd_c in range(10):
                if (mask ^ (1 << odd_c)) in freq:
                    ans += freq[mask ^ (1 << odd_c)]
        
        return ans
        