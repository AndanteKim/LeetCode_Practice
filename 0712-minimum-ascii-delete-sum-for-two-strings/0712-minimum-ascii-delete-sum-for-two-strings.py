class Solution:
    def minimumDeleteSum(self, s1: str, s2: str) -> int:
        
        @lru_cache(maxsize = None)
        def compute_cost(i: int, j: int) -> int:
            if i < 0:
                delete_cost = 0
                for pointer in range(j + 1):
                    delete_cost += ord(s2[pointer])
                return delete_cost
            
            if j < 0:
                delete_cost = 0
                for pointer in range(i + 1):
                    delete_cost += ord(s1[pointer])
                return delete_cost
            
            if s1[i] == s2[j]:
                return compute_cost(i - 1, j - 1)
            else:
                return min(ord(s1[i]) + compute_cost(i - 1, j), ord(s2[j]) + compute_cost(i, j - 1), \
                          ord(s1[i]) + ord(s2[j]) + compute_cost(i - 1, j - 1))
            
        return compute_cost(len(s1) - 1, len(s2) - 1)