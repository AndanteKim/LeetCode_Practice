class Solution:
    def minimumDeletions(self, s: str) -> int:
        n = len(s)
        cnt_a, cnt_b = [0] * n, [0] * n
        b_cnt = 0
        
        # First pass: Compute cnt_b storing the number of
        # 'b' characters to the left of the current position
        for i in range(n):
            cnt_b[i] = b_cnt
            if s[i] == 'b':
                b_cnt += 1
                
        a_cnt = 0
        # Second pass: Compute cnt_a storing the number of
        # 'a' characters to the right of the current position
        for i in range(n - 1, -1, -1):
            cnt_a[i] = a_cnt
            if s[i] == 'a':
                a_cnt += 1
                
        min_deletions = n
        
        # Third pass: Iterate through the string to find the minimum deletions
        for i in range(n):
            min_deletions = min(min_deletions, cnt_a[i] + cnt_b[i])
            
        return min_deletions