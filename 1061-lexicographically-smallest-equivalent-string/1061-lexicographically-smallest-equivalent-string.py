class Solution:
    minChar = 2**31 - 1
    def DFS(self, src: int, adjMatrix: List[List[int]], visited: List[int], component: List[int]):
        visited[src] = 1
        component.append(src)
        self.minChar = min(self.minChar, src)
        
        for i in range(26):
            if (adjMatrix[src][i] != None and visited[i] == None):
                self.DFS(i, adjMatrix, visited, component)
    
    def smallestEquivalentString(self, s1: str, s2: str, baseStr: str) -> str:
        adjMatrix = [[None] * 26 for _ in range(26)]
        for i in range(len(s1)):
            adjMatrix[ord(s1[i]) - ord('a')][ord(s2[i]) - ord('a')] = 1
            adjMatrix[ord(s2[i]) - ord('a')][ord(s1[i]) - ord('a')] = 1
        
        mappingChar = [i for i in range(26)]
        visited = [None] *26
        for c in range(26):
            if visited[c] == None:
                component = []
                self.minChar = 27
                self.DFS(c, adjMatrix, visited, component)
                
                for vertex in component:
                    mappingChar[vertex] = self.minChar
                    
        ans = ""
        for c in baseStr:
            ans += chr(mappingChar[ord(c) - ord('a')] + ord('a'))
        
        return ans