class Solution:
    def shortestWordDistance(self, wordsDict: List[str], word1: str, word2: str) -> int:
        ans = float('inf')
        w1_loc, w2_loc = [], []
        
        for i in range(len(wordsDict)):
            if wordsDict[i] == word1:
                w1_loc.append(i)
            if wordsDict[i] == word2:
                w2_loc.append(i)
        
        for i in w1_loc:
            x = bisect_right(w2_loc, i)
            if x != len(w2_loc):
                ans = min(ans, w2_loc[x] - i)
            
            if x != 0 and w2_loc[x - 1] != i:
                ans = min(ans, i - w2_loc[x - 1])
        
        return ans
            