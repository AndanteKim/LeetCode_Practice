class Solution:
    def shortestWordDistance(self, wordsDict: List[str], word1: str, word2: str) -> int:
        ans = float('inf')
        
        w1_loc, w2_loc = [], []
        
        for i in range(len(wordsDict)):
            if wordsDict[i] == word1:
                w1_loc.append(i)
            if w1_loc and w2_loc and w1_loc[-1] != w2_loc[-1]:
                ans = min(ans, abs(w1_loc[-1] - w2_loc[-1]))
            if wordsDict[i] == word2:
                w2_loc.append(i)
        if w1_loc[-1] != w2_loc[-1]:
            ans = min(ans, abs(w1_loc[-1] - w2_loc[-1]))
        
        return ans
            