class Solution:
    def reverseVowels(self, s: str) -> str:
        i, j, ans = 0, len(s) - 1, [c for c in s]
        vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'}
        while i < j:
            if ans[i] not in vowels:
                i += 1
            
            if ans[j] not in vowels:
                j -= 1
            
            if ans[i] in vowels and ans[j] in vowels:
                ans[i], ans[j] = ans[j], ans[i]
                i += 1
                j -= 1
        return "".join(ans)