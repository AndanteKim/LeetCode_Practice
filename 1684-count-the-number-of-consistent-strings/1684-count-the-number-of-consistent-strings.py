class Solution:
    def countConsistentStrings(self, allowed: str, words: List[str]) -> int:
        ans, allow_chars = 0, set(allowed)
        
        for word in words:
            flag = True
            for c in word:
                if c not in allow_chars:
                    flag = False
                    break
                    
            if flag:
                ans += 1
                
        return ans