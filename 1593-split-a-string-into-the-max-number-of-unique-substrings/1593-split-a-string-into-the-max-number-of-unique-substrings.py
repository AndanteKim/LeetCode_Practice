class Solution:
    def maxUniqueSplit(self, s: str) -> int:
        # Backtrack with pruning
        def backtrack(start: int, count: int, max_count: List[int]) -> int:
            if count + n - start <= max_count[0]:
                return
            
            if start == n:
                max_count[0] = max(max_count[0], count)
                return
            
            for end in range(start + 1, n + 1):
                sub_str = s[start : end]
                if sub_str not in seen:
                    seen.add(sub_str)
                    backtrack(end, count + 1, max_count)
                    seen.remove(sub_str)
        
        n, seen, max_count = len(s), set(), [0]
        backtrack(0, 0, max_count)
        return max_count[0]