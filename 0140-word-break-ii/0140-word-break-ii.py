class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> List[str]:
        # Convert wordDict to a set for O(1) lookups
        word_set, self.n = set(wordDict), len(s)
        ans = []
        
        # Start the backtracking process
        self._backtrack(s, word_set, [], ans, 0)

        return ans
    
    def _backtrack(self, s: str, word_set: set, curr: List[str], ans: List[str], start: int) -> None:
        # If we've reached the end of the string, add the current sentence to results
        if start == self.n:
            ans.append(" ".join(curr))
            return
        
        # Iterate over possible end indices
        for end in range(start + 1, self.n + 1):
            word = s[start:end]
            
            # If the word is in the set, proceed with backtracking
            if word in word_set:
                curr.append(word)
                # Recursively call backtrack with the new end index
                self._backtrack(s, word_set, curr, ans, end)
                
                # Remove the last word to backtrack
                curr.pop()
                