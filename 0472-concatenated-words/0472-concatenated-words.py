class Solution:
    def dfs(self, word: str, length: int, visited: List[bool], dictionary: Set[str]) -> bool:
        if length == len(word):
            return True
        if visited[length]:
            return False
        visited[length] = True
        start = 1 if length == 0 else 0
        for i in range(len(word) - start, length, -1):
            if word[length:i] in dictionary and self.dfs(word, i, visited, dictionary):
                return True
        return False
    
    def findAllConcatenatedWordsInADict(self, words: List[str]) -> List[str]:
        
        dictionary = {word for word in words}
        ans = []
        for word in words:
            visited = [False] * len(word)
            if (self.dfs(word, 0, visited, dictionary)):
                ans.append(word)
        return ans