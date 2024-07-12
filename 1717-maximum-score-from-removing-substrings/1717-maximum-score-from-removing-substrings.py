class Solution:
    def maximumGain(self, s: str, x: int, y: int) -> int:
        # Ensure "ab" always has higher points than "ba"
        if x < y:
            # Reverse the string to maintain logic
            s = s[::-1]
            # Swap points
            x, y = y, x
            
        a_cnt, b_cnt, ans = 0, 0, 0
        
        for i in range(len(s)):
            if s[i] == 'a':
                a_cnt += 1
                
            elif s[i] == 'b':
                if a_cnt > 0:
                    # Can form "ab", remove it and add points
                    a_cnt -= 1
                    ans += x
                else:
                    # Can't form "ab", keep 'b' for potential future "ba"
                    b_cnt += 1
            
            else:
                # Non 'a' or 'b' character encountered
                # Calculate points for any remaining "ba" pairs
                ans += min(b_cnt, a_cnt) * y
                # Reset counters for next segment
                a_cnt = b_cnt = 0
                
        # Calculate points for any remaining "ba" pairs at the end
        ans += min(b_cnt, a_cnt) * y
        
        return ans