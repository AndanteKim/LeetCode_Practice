class Solution:
    def reverseWords(self, s: str) -> str:
        s = [c for c in s]
        lastSpaceIndex, length = -1, len(s)
        
        for strIndex in range(length+1):
            if strIndex == length or s[strIndex] == " ":
                startIndex, endIndex = lastSpaceIndex + 1, strIndex - 1
                while startIndex < endIndex:
                    s[startIndex], s[endIndex] = s[endIndex], s[startIndex]
                    startIndex += 1
                    endIndex -= 1
                lastSpaceIndex = strIndex
        return "".join(s)
            