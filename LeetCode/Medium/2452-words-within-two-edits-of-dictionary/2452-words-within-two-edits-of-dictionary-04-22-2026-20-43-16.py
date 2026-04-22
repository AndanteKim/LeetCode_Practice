class Solution:
    def twoEditWords(self, queries: List[str], dictionary: List[str]) -> List[str]:
        ans = []
        
        for word1 in queries:
            n = len(word1)
            for word2 in dictionary:
                flag, edits = True, 0
                for i in range(n):
                    if word1[i] != word2[i]:
                        edits += 1
                    
                    if edits > 2:
                        flag = False
                        break
                
                if flag:
                    ans.append(word1)
                    break
        
        return ans
                