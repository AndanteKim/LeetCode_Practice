class Solution:
    representative = [0] * 26
    
    def find(self, x: int) -> int:
            if (self.representative[x] == x): return x
            return self.find(self.representative[x])
        
    def performUnion(self, x: int, y: int) -> None:
        x = self.find(x)
        y = self.find(y)
        if x == y: return
            
        if (x < y):
            self.representative[y] = x
        else:
            self.representative[x] = y
    
    def smallestEquivalentString(self, s1: str, s2: str, baseStr: str) -> str:
        ans = ""
        for i in range(26):
            self.representative[i] = i
        
        for i in range(len(s1)):
            self.performUnion(ord(s1[i]) - ord('a'), ord(s2[i]) - ord('a'))
        
        for c in baseStr:
            ans += chr(self.find(ord(c)-ord('a')) + ord('a'))
        
        return ans
            
        
        