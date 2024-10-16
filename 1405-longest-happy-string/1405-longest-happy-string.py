class Solution:
    def longestDiverseString(self, a: int, b: int, c: int) -> str:
        curr_a, curr_b, curr_c = 0, 0, 0
        # Maximum total iterations possible is given by the sum of a, b, and c.
        total_iter, ans = a + b + c, ""
        
        for i in range(total_iter):
            if (a >= max(b, c) and curr_a < 2) or (a > 0 and (curr_b == 2 or curr_c == 2)):
                # If 'a' is maximum and its streak is less than 2, or if streak of 'b' or 'c' is 2, then 'a' will be\
                # the next character.
                ans += 'a'
                a -= 1
                curr_a += 1
                curr_b, curr_c = 0, 0
                
            elif (b >= max(a, c) and curr_b < 2) or (b > 0 and (curr_a == 2 or curr_c == 2)):
                # If 'b' is maximum and its streak is less than 2, or if streak of 'a' or 'c' is 2, then 'b' will be
                # the next character.
                ans += 'b'
                b -= 1
                curr_b += 1
                curr_a, curr_c = 0, 0
            
            elif (c >= max(a, b) and curr_c < 2) or (c > 0 and (curr_a == 2 or curr_b == 2)):
                # If 'c' is the maximum and its streak is less than 2, or if streak of 'a' or 'b' is 2, then 'c' will be
                # the next character.
                ans += 'c'
                c -= 1
                curr_c += 1
                curr_a, curr_b = 0, 0
                
        return ans
                
                