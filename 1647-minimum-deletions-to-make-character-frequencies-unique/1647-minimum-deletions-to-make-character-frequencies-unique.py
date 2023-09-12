class Solution:
    def minDeletions(self, s: str) -> int:
        
        # store the frequency of each character
        frequencies = [0] * 26
        for c in s:
            frequencies[ord(c) - 97] += 1
        
        ans = 0
        # Use a set to store the frequencies we've already seen
        seen = set()
        
        for i in range(26):
            # Keep decrementing the frequencies we've already seen
            while frequencies[i] and frequencies[i] in seen:
                frequencies[i] -= 1
                ans += 1
                
            # Add the newly occupied frequency to the set
            seen.add(frequencies[i])
        
        return ans
        
                    
        