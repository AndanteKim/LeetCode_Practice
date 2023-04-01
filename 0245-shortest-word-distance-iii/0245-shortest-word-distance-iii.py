class Solution:
    def shortestWordDistance(self, wordsDict: List[str], word1: str, word2: str) -> int:
        ans, prevIndex = float('inf'), -1
        
        for i in range(len(wordsDict)):
            if wordsDict[i] == word1 or wordsDict[i] == word2:
                if prevIndex != -1 and (wordsDict[prevIndex] != wordsDict[i] or word1 == word2):
                    ans = min(ans, i - prevIndex)
                prevIndex = i
            
        return ans
            