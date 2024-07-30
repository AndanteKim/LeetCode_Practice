class Solution:
    def minimumDeletions(self, s: str) -> int:
        n = len(s)
        count_a, a_cnt = [0] * n, 0
        
        # First pass: compute count_a storing the number of
        # 'a' characters to the right of the current position
        for i in range(n - 1, -1, -1):
            count_a[i] = a_cnt
            if s[i] == 'a':
                a_cnt += 1
        
        min_deletions, b_cnt = n, 0
        # Second pass: compute minimum deletions on the fly
        for i in range(n):
            min_deletions = min(count_a[i] + b_cnt, min_deletions)
            if s[i] == 'b':
                b_cnt += 1
                
        return min_deletions