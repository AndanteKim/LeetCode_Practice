class Solution:
    def areSentencesSimilar(self, sentence1: List[str], sentence2: List[str], similarPairs: List[List[str]]) -> bool:
        m, n = len(sentence1), len(sentence2)
        if m != n: return False
        wordToSimilarWords = defaultdict(set)
        for word1, word2 in similarPairs:
            wordToSimilarWords[word1].add(word2)
            wordToSimilarWords[word2].add(word1)
            
        for i in range(m):
            if sentence1[i] == sentence2[i] or sentence2[i] in wordToSimilarWords[sentence1[i]]:
                continue
            return False
        return True