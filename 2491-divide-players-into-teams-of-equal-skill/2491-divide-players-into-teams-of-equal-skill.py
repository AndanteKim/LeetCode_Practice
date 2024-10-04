class Solution:
    def dividePlayers(self, skill: List[int]) -> int:
        n, skill_seen = len(skill), defaultdict(int) 
        pair_remain = (n >> 1)
        target_skill, ans = sum(skill) // pair_remain, 0
        
        for curr_skill in skill:
            partner_skill = target_skill - curr_skill
            if skill_seen[partner_skill] > 0:
                ans += curr_skill * partner_skill
                skill_seen[partner_skill] -= 1
                pair_remain -= 1
            else:
                skill_seen[curr_skill] += 1
        
        # If all the pairs match, 
        return ans if pair_remain == 0 else -1