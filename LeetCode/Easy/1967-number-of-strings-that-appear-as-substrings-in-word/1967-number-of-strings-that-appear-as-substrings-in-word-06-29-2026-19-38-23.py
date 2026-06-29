class Solution:
    def numOfStrings(self, patterns: List[str], word: str) -> int:
        def check(pattern: str, word: str) -> bool:
            m, n = len(pattern), len(word)

            # Generate the prefix array of the pattern
            pi, j = [0] * m, 0
            
            for i in range(1, m):
                while j and pattern[i] != pattern[j]:
                    j = pi[j - 1]
                if pattern[i] == pattern[j]:
                    j += 1
                pi[i] = j

            # Using prefix arrays for matching
            j = 0

            for i in range(n):
                while j and word[i] != pattern[j]:
                    j = pi[j - 1]
                if word[i] == pattern[j]:
                    j += 1
                if j == m:
                    return True
            
            return False
        
        ans = 0
        for p in patterns:
            ans += check(p, word)

        return ans