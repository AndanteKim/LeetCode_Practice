class Solution:
    def minimumPushes(self, word: str) -> int:
        # Frequency list to store count of each letter
        freq = [0] * 26
        
        # Count occurrences of each letter
        for c in word:
            freq[ord(c) - 97] += 1
            
        # Sort frequencies in descending order
        freq.sort(reverse = True)
        
        ans = 0
        
        # Calculate total number of presses
        for i in range(26):
            if freq[i] == 0:
                break
                
            ans += ((i // 8) + 1) * freq[i]
            
        return ans