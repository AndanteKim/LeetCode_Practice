class Solution:
    def evaluate(self, s: str, knowledge: list[list[str]]) -> str:
        kle = dict()
        for k, v in knowledge:
            kle[k] = v
        
        i, n = 0, len(s)
        ans = ""

        while i < n:
            if s[i] == '(':
                curr = ""
                j = i + 1
                while s[j] != ')':
                    curr += s[j]
                    j += 1
                i = j

                if curr in kle:
                    ans += kle[curr]
                else:
                    ans += '?'

            else:
                ans += s[i]

            i += 1

        return ans