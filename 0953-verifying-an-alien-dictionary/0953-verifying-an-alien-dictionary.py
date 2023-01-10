class Solution:
    def isAlienSorted(self, words: List[str], order: str) -> bool:
        lookup_order = {o:idx for idx, o in enumerate(order)}
        
        for i in range(len(words)-1):
            for j in range(len(words[i])):
                if j >= len(words[i+1]): return False
                
                if words[i][j] != words[i+1][j]:
                    if lookup_order[words[i][j]] > lookup_order[words[i+1][j]]: return False
                    break
        
        return True