class Solution:
    def countWords(self, words1: List[str], words2: List[str]) -> int:
        # Use hash map to find count of words
        freq1, freq2 = Counter(words1), Counter(words2)
        ans = 0
        
        # Find the common words and its frequency is 1.
        for word, freq in freq1.items():
            if word in freq2 and freq == 1 and freq2[word] == 1:
                ans += 1
                
        return ans