class Solution:
    def isValid(self, s: str) -> bool:
        mapping, st = {')':'(', '}':'{', ']':'['}, []

        for c in s:
            if c in mapping:
                if not st or st[-1] != mapping[c]:
                    return False
                st.pop()
            else:
                st.append(c)

        return True if not st else False