class Solution:
    def isAlienSorted(self, words: List[str], order: str) -> bool:
        ordered_map = dict()
        for idx, val in enumerate(order):
            ordered_map[val] = idx
            
        for i in range(len(words) - 1):
            for j in range(len(words[i])):
                if j >= len(words[i + 1]): return False
            
                if words[i][j] != words[i+1][j]:
                    if ordered_map[words[i][j]] > ordered_map[words[i+1][j]]: return False
                    break
        return True