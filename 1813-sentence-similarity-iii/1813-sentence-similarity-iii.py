class Solution:
    def areSentencesSimilar(self, sentence1: str, sentence2: str) -> bool:
        # Split the words in sentences and store it in a string array.
        s1_words, s2_words = sentence1.split(), sentence2.split()
        
        # If words in s1 are more than s2, swap them and return the answer
        if len(s1_words) > len(s2_words):
            return self.areSentencesSimilar(sentence2, sentence1)
        
        start, ends1, ends2 = 0, len(s1_words) - 1, len(s2_words) - 1
        # Find the maximum words matching from the beginning.
        while start < len(s1_words) and s1_words[start] == s2_words[start]:
            start += 1
            
        # Find the maximum words matching in the end.
        while ends1 >= 0 and s1_words[ends1] == s2_words[ends2]:
            ends1 -= 1
            ends2 -= 1
            
        # If i reaches the end of the array, then we return true.
        return ends1 < start
        