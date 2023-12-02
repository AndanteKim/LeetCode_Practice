class Solution:
    def countCharacters(self, words: List[str], chars: str) -> int:
        cnt_chars, ans = [0] * 26, 0
        for c in chars:
            cnt_chars[ord(c) - 97] += 1
        
        for word in words:
            available, remain_chars = True, cnt_chars[:]
            for c in word:
                if remain_chars[ord(c) - 97] == 0:
                    available = False
                    break
                remain_chars[ord(c) - 97] -= 1
            if available:
                ans += len(word)
        
        return ans