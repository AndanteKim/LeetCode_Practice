class Solution:
    def checkStrings(self, s1: str, s2: str) -> bool:
        def check_balance(chars: Dict[chr, int]) -> bool:
            for c, cnt in chars.items():
                if cnt != 0:
                    return True
            
            return False
        
        even_chars, odd_chars = dict(), dict()
        n = len(s1)

        for i in range(n):
            if i % 2:
                odd_chars[s1[i]] = odd_chars.get(s1[i], 0) + 1
                odd_chars[s2[i]] = odd_chars.get(s2[i], 0) - 1
            else:
                even_chars[s1[i]] = even_chars.get(s1[i], 0) + 1
                even_chars[s2[i]] = even_chars.get(s2[i], 0) - 1
        
        if check_balance(odd_chars) or check_balance(even_chars):
            return False

        return True
