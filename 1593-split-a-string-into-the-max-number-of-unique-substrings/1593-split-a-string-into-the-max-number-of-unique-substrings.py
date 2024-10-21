class Solution:
    def maxUniqueSplit(self, s: str) -> int:
        def backtrack(i: int, curr: str, seen: Set[str]) -> int:
            #print(seen)
            if i == n:
                return len(seen)
            
            max_split = 0
            curr += s[i]
            if curr not in seen:
                seen.add(curr)
                max_split = backtrack(i + 1, "", seen)
                seen.remove(curr)
            max_split = max(max_split, backtrack(i + 1, curr, seen))
                
            return max_split
        
        n, seen = len(s), set()
        return backtrack(0, "", seen)