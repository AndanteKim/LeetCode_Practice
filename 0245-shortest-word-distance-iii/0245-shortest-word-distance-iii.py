class Solution:
    def shortestWordDistance(self, wordsDict: List[str], word1: str, word2: str) -> int:
        ans = float('inf')
        indices = []
        
        for i in range(len(wordsDict)):
            if wordsDict[i] == word1:
                indices.append((i, 0))
            if wordsDict[i] == word2:
                indices.append((i, 1))
        
        for i in range(len(indices) - 1):
            if indices[i][1] != indices[i + 1][1] and indices[i][0] != indices[i+1][0]:
                ans = min(ans, indices[i + 1][0] - indices[i][0])
        
        return ans
            