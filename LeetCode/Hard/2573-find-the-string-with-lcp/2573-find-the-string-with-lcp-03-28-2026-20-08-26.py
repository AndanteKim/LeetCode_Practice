class Solution:
    def findTheString(self, lcp: List[List[int]]) -> str:
        n = len(lcp)
        word, curr = [""] * n, 97

        # Construct the string starting from 'a' to 'z' sequentially
        for i in range(n):
            if not word[i]:
                if curr > ord('z'):
                    return ""
                
                word[i] = chr(curr)
                for j in range(i + 1, n):
                    if lcp[i][j]:
                        word[j] = word[i]
                curr += 1
        
        # Verify if the constructed string meets the LCP matrix requirements
        for i in range(n - 1, -1, -1):
            for j in range(n - 1, -1, -1):
                if word[i] != word[j]:
                    if lcp[i][j]:
                        return ""
                else:
                    if i == n - 1 or j == n - 1:
                        if lcp[i][j] != 1:
                            return ""
                    else:
                        if lcp[i][j] != lcp[i + 1][j + 1] + 1:
                            return ""
        
        return "".join(word)