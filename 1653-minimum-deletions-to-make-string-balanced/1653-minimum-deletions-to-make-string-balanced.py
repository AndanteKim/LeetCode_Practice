class Solution:
    def minimumDeletions(self, s: str) -> int:
        n, a_count, b_count = len(s), s.count('a'), 0
        min_deletions = n
        
        # Second pass: Iterate through the string to compute minimum deletions
        for i in range(n):
            if s[i] == 'a':
                a_count -= 1
            
            min_deletions = min(min_deletions, a_count + b_count)
            if s[i] == 'b':
                b_count += 1
                
        return min_deletions
        