class Solution:
    memo = [[]]
    def minDistance(self, word1: str, word2: str) -> int:
        self.memo = [[-1 for j in range(len(word2) + 1)] for i in range(len(word1) + 1)]
        return self.minDistanceRecur(word1, word2, len(word1), len(word2))
    
    def minDistanceRecur(self, word1: str, word2: str, word1Index: int, word2Index: int) -> int:
        if word1Index == 0:
            return word2Index
        if word2Index == 0:
            return word1Index
        
        if self.memo[word1Index][word2Index] != -1:
            return self.memo[word1Index][word2Index]
        
        minEditDistance = 0
        if word1[word1Index - 1] == word2[word2Index - 1]:
            minEditDistance = self.minDistanceRecur(word1, word2, word1Index - 1, word2Index - 1)
        else:
            insertOperation = self.minDistanceRecur(word1, word2, word1Index, word2Index - 1)
            deleteOperation = self.minDistanceRecur(word1, word2, word1Index - 1, word2Index)
            replaceOperation = self.minDistanceRecur(word1, word2, word1Index - 1, word2Index - 1)
            minEditDistance = min(insertOperation, deleteOperation, replaceOperation) + 1
        self.memo[word1Index][word2Index] = minEditDistance
        return minEditDistance