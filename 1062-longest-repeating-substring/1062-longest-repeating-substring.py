class Solution:
    def longestRepeatingSubstring(self, s: str) -> int:
        n = len(s)
        suffixes = []
        
        # Create suffix array by storing all suffixes of the string
        for i in range(n):
            suffixes.append(s[i:])
            
        # Sort the suffix array using MSD Radix Sort
        self._msd_radix_sort(suffixes)
        
        max_len = 0
        
        # Compare adjacent suffixes to find the longest common prefix
        for i in range(1, n):
            j = 0
            
            # Compare characters one by one until they
            # differ or end of one suffix is reached
            while (j < min(len(suffixes[i]), len(suffixes[i - 1])) and suffixes[i - 1][j] == suffixes[i][j]):
                j += 1
                
            # Update max length with the length of the common prefix
            max_len = max(max_len, j)
            
        return max_len
    
    def _msd_radix_sort(self, input: List[str]) -> None:
        aux = ["" for _ in input]
        self._sort(input, 0, len(input) - 1, 0, aux)
        
    def _sort(self, input: List[str], lo: int, hi: int, depth: int, aux: List[str]) -> None:
        if lo >= hi:
            return
        
        count = [0] * 28
        # Count frequencies of each character at the current depth
        for i in range(lo, hi + 1):
            count[self._char_at(input[i], depth) + 1] += 1
            
        # Compute cumulates which give positions of each character
        for i in range(1, 28):
            count[i] += count[i - 1]
            
        # Move items to auxiliary array based on cumulates
        for i in range(lo, hi + 1):
            aux[count[self._char_at(input[i], depth)]] = input[i]
            count[self._char_at(input[i], depth)] += 1
            
        # Copy back to original array
        for i in range(lo, hi + 1):
            input[i] = aux[i - lo]
            
        # Recursively sort for each character value
        for i in range(27):
            self._sort(input, lo + count[i], lo + count[i + 1] - 1, depth + 1, aux)
            
    def _char_at(self, s: str, index: int) -> int:
        if index >= len(s):
            return 0
        
        return ord(s[index]) - 97 + 1
            