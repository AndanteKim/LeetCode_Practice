class Solution:
    def uncommonFromSentences(self, s1: str, s2: str) -> List[str]:
        freq_words = dict()
        
        for word in s1.split():
            freq_words[word] = freq_words.get(word, 0) + 1
            
        for word in s2.split():
            freq_words[word] = freq_words.get(word, 0) + 1
            
        ans = []
        for word, freq in freq_words.items():
            if freq == 1:
                ans.append(word)
                
        return ans