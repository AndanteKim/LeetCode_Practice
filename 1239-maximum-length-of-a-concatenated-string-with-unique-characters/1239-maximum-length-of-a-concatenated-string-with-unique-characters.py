class Solution:
    def maxLength(self, arr: List[str]) -> int:
        # Results initialized as a Set to prevent duplicates
        results, ans = set([0]), 0
        
        # Check eeach string in arr and find the best length
        for word in arr:
            ans = max(ans, self.add_word(word, results))
        return ans

    def add_word(self, word: str, results: List[str]) -> int:
        # Initialize an int used as a character set
        char_bitset, ans = 0, 0
        
        for ch in word:
            # Define character mask for current chaar
            mask = 1 << ord(ch) - 97
            
            # Bitwise AND check using character mask to see
            # if char already found and if so, exit
            if char_bitset & mask > 0:
                return 0
            
            # Mark char as seen in char_bitset
            char_bitset += mask
        
        # If the initial bitset is already a known result
        # then any possible new results will have already been found
        if char_bitset + (len(word) << 26) in results:
            return 0
        
        # Iterate through previous results only
        for res in list(results):
            # If the two bitsets overlap, skip to the next result
            if res & char_bitset:
                continue
                
            # Build the new entry with bit manipulation
            new_res_len = (res >> 26) + len(word)
            new_char_bitset = char_bitset + res & ((1 << 26) - 1)
            
            # Merge the two into one, add it to results and keep track of the longest so far
            results.add((new_res_len << 26) + new_char_bitset)
            ans = max(ans, new_res_len)
        return ans