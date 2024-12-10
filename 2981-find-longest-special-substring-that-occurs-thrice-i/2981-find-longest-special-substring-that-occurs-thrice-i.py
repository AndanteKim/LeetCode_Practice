class Solution:
    def maximumLength(self, s: str) -> int:
        # Create a dictionary to store the count of all substrings
        cnt, cnt_strs = dict(), 0
        
        for start in range(len(s)):
            ch, substr_len = s[start], 0
            
            for end in range(start, len(s)):
                # If the string is empty, or the current character is equal to
                # the previously added character, then add it to the map.
                if ch == s[end]:
                    substr_len += 1
                    cnt[(ch, substr_len)] = (cnt.get((ch, substr_len), 0) + 1)
                else:
                    break
                    
        # Create a variable ans to store the longest length of substring with
        # frequency at least 3.
        ans = 0
        for i in cnt.items():
            length = i[0][1]
            if i[1] >= 3 and length > ans:
                ans = length
        
        return -1 if ans == 0 else ans