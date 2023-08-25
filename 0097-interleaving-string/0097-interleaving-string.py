class Solution:
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        
        @lru_cache(maxsize = None)
        def dp(i: int, j: int, k: int) -> bool:
            if k == n3:
                if i == 0 or j == 0:
                    return False
                return True
            
            if i >= n1 and j >= n2:
                return False
            
            can_interleaving = False
            if i < n1 and s3[k] == s1[i]:
                can_interleaving = can_interleaving or dp(i + 1, j, k + 1)
            
            if j < n2 and s3[k] == s2[j]:
                can_interleaving = can_interleaving or dp(i, j + 1, k + 1)
            
            return can_interleaving
        
        n1, n2, n3 = len(s1), len(s2), len(s3)
        if n1 + n2 == 0:
            if s3:
                return False
            return True
        elif n1 + n2 != n3:
            return False
        elif not n1 or not n2:
            if s1 == s3 or s2 == s3:
                return True
            return False
        return dp(0, 0, 0)