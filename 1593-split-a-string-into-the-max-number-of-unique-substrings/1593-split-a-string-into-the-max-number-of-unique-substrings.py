class Solution:
    def maxUniqueSplit(self, s: str) -> int:
        def backtrack(start: int) -> int:
            # Base case
            if start == n:
                return 0
            
            max_count = 0
            
            for end in range(start + 1, n + 1):
                sub_str = s[start:end]
                if sub_str not in seen:
                    seen.add(sub_str)
                    max_count = max(max_count, 1 + backtrack(end))
                    seen.remove(sub_str)
                    
            return max_count
        
        n, seen = len(s), set()
        return backtrack(0)