class Solution:
    def reorganizeString(self, s: str) -> str:
        char_counts = Counter(s)
        max_cnt, letter = 0, ''
        for char, cnt in char_counts.items():
            if cnt > max_cnt:
                max_cnt = cnt
                letter = char
        
        if max_cnt > (len(s) + 1) // 2:
            return ""
        ans, index = [''] * len(s), 0
        
        while char_counts[letter] != 0:
            ans[index] = letter
            index += 2
            char_counts[letter] -= 1
        
        for char, cnt in char_counts.items():
            while cnt > 0:
                if index >= len(s):
                    index = 1
                ans[index] = char
                index += 2
                cnt -= 1
        
        return "".join(ans)
        
            