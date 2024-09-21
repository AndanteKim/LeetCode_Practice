class Solution:
    def shortestPalindrome(self, s: str) -> str:
        hash_base, mod, n = 29, 10 ** 9 + 7, len(s)
        forward_hash, reversed_hash = 0, 0
        power, palindrome_end_idx = 1, -1
        
        # Calculate rolling hashes and find the longest palindromic prefix
        for i in range(n):
            # Update forward hash
            forward_hash = (forward_hash * hash_base + (ord(s[i]) - 97 + 1)) % mod
            
            # Update reverse hash
            reversed_hash = (reversed_hash + (ord(s[i]) - 97 + 1) * power) % mod
            
            power = (power * hash_base) % mod
            
            # If forward and reverse hashes match, update palindrome end index
            if forward_hash == reversed_hash:
                palindrome_end_idx = i
            
        # Find the remaining suffix after the longest palindromic prefix
        suffix = s[palindrome_end_idx + 1 :]
        
        # Reverse the remaining suffix
        reversed_suffix = suffix[::-1]
        
        # Prepend the reversed suffix to the original string and return the result
        return reversed_suffix + s
        