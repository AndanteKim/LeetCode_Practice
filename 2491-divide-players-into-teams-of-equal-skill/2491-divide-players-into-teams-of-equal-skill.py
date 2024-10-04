class Solution:
    def dividePlayers(self, skill: List[int]) -> int:
        # Base case
        # if len(skill) == 2:
        #    return skill[0] * skill[1]
        
        n, seen = len(skill), defaultdict(int) 
        pair_remain = (n >> 1)
        avg, ans = sum(skill) // pair_remain, 0
        
        for s in skill:
            if seen[avg - s] > 0:
                ans += s * (avg - s)
                seen[avg - s] -= 1
                pair_remain -= 1
            else:
                seen[s] += 1
        
        return ans if pair_remain == 0 else -1