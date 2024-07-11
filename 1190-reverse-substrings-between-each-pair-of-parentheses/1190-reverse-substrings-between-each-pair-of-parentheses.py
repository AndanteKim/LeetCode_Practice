class Solution:
    def reverseParentheses(self, s: str) -> str:
        n = len(s)
        open_parentheses_idx = []
        pair = [0] * n
        
        # First pass: Pair up parentheses
        for i in range(n):
            if s[i] == "(":
                open_parentheses_idx.append(i)
            if s[i] == ")":
                j = open_parentheses_idx.pop()
                pair[i] = j
                pair[j] = i
                
        # Second pass: Build the result string
        ans = []
        curr_idx, dirs = 0, 1
        
        while curr_idx < n:
            if s[curr_idx] == "(" or s[curr_idx] == ")":
                curr_idx = pair[curr_idx]
                dirs = -dirs
            else:
                ans.append(s[curr_idx])
            curr_idx += dirs
            
        return "".join(ans)