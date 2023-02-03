class Solution:
    def frequencySort(self, s: str) -> str:
        if not s:
            return s
        
        s = list(s)
        s.sort()
        all_strings = []
        cur_sb = [s[0]]
        for c in s[1:]:
            if cur_sb[-1] != c:
                all_strings.append("".join(cur_sb))
                cur_sb = []
            cur_sb.append(c)
        all_strings.append("".join(cur_sb))
        
        all_strings.sort(key = lambda string: len(string), reverse = True)
        return "".join(all_strings)